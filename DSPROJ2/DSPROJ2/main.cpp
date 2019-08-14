
#include<fstream>
#include<ostream>
#include<string>
#include<vector>
#include<algorithm>
#include <utility>
#include<map>

#include"Huffman.cpp"
using namespace std;

string tobinary(unsigned char code, unsigned char numofzero);//��������ļ�ת�ɶ������ļ�
void readEncodefile(string file);//��ȡ�������ļ�
void readDecodefile(string file);//��ȡ�������ļ�
bool cmpsort(const pair<char, int>&element1, const pair<char, int>&element2);//������Ĵ������ַ������ִ�������
vector<pair<char, int>> buildtable();//���������ַ�����ִ�����ӳ���
bool heapsort(HuffNode *element1, HuffNode *element2);//Huffman����ʱ����������
HuffNode* bulidHuffman();//����Huffman��
void recursion_encodeing(HuffNode* root, string code, map<char, string> &chencode);//�ݹ鴴��ÿ����Ӧ�ַ�����
string encode();//����������ı�
string decode();//����������ı�
string changetoHuffmanCode(string code);//���������ı�ת��ΪHuffman����
void outputencodefile(string file);//����������ļ�
void outputdecodefile(string file);//����������ļ�
void menu();//��ӡ�˵�
string text;

map<string, char> decodetable;
int chsize;
int textsize;
map<char, string> chencode;
unsigned char wirtezero;
string tobinary(unsigned char code, unsigned char numofzero)
{
	int asciicode = code;
	string binarycode;
	for (int i = 0; i < 8; i++)
	{
		if ((asciicode - pow(2, 8 - i - 1)) >= 0)
		{
			binarycode += "1";
			//cout << asciicode << " ";
			asciicode -= pow(2, 8 - i - 1);
		}
		else
			binarycode += "0";
	}
	//cout << endl;
	while (numofzero > 0)
	{
		if (binarycode.size() == 0)
			break;
		binarycode.erase(binarycode.size() - 1);
		numofzero--;
	}
	return binarycode;
}



void readEncodefile(string file)
{
	ifstream infile;
	infile.open(file.data());
	if (!infile.is_open())
	{
		cout << "��ȡ�ļ�ʧ�ܣ�";
		system("pause");
		exit(0);
	}
	while (true)
	{
		//string temp;
		char ch = infile.get();
		if (ch == -1)
			break;
		text += ch;
	}
}
void readDecodefile(string file)
{
	ifstream infile;
	infile.open(file.data());
	if (!infile.is_open())
	{
		cout << "��ȡ�ļ�ʧ�ܣ�";
		system("pause");
		exit(0);
	}
	unsigned char check1 = infile.get();
	unsigned char check2 = infile.get();
	if (check1 != '|' || check2 != '{')
	{
		cout << "�����ļ������ϱ���������ʽ�����س��˳���";
		system("pause");
		exit(0);
	}
	infile >> chsize;
	infile.get();
	infile >> textsize;
	if (chsize == 0 || textsize == 0)
	{
		cout << "�����ļ������ϱ���������ʽ�����س��˳���";
		system("pause");
		exit(0);

	}
	for (int i = 0; i < chsize; i++)
	{
		char ch;
		ch = infile.get();
		unsigned char code = infile.get();
		unsigned char numofzero = infile.get();
		string binarycode = tobinary(code, numofzero);
		decodetable[binarycode] = ch;
		unsigned char check3 = infile.get();
		if (check3 != '0')
		{
			cout << "�����ļ������ϱ���������ʽ�����س��˳���";
			system("pause");
			exit(0);
		}
		//cout << (int)ch << ":" << binarycode <<endl;
	}
	text.clear();
	for (int i = 0; i < textsize; i++)
	{
		string temp;
		char ch = infile.get();
		string decodech;
		if (i < textsize - 1)
			decodech = tobinary(ch, 0);
		else
		{
			unsigned char numofzero = infile.get();
			decodech = tobinary(ch, numofzero);
		}
		text += decodech;
	}

	//cout << text << endl;

}
bool cmpsort(const pair<char, int>&element1, const pair<char, int>&element2)
{
	return element1.second < element2.second;
}

vector<pair<char, int>> buildtable()
{
	map<char, int> huffmanmap;
	for (char eachch : text)
	{
		huffmanmap[eachch] += 1;
	}
	vector<pair<char, int>> sortmap;
	for (auto it = huffmanmap.begin(); it != huffmanmap.end(); it++)
	{
		sortmap.push_back(make_pair(it->first, it->second));
	}
	sort(sortmap.begin(), sortmap.end(), cmpsort);
	/*
	for (auto it = sortmap.begin(); it != sortmap.end(); it++)
	{
		cout << it->first << ":" << it->second<<endl;
	}*/
	chsize = sortmap.size();
	return sortmap;
}
bool heapsort(HuffNode *element1, HuffNode *element2)
{
	return element1->weight() < element2->weight();
}


HuffNode* bulidHuffman()
{
	vector<pair<char, int>> chtable = buildtable();
	vector<HuffNode*> bulidtree;
	for (auto it = chtable.begin(); it != chtable.end(); it++)
	{
		HuffNode* temp = new LeafNode(it->first, it->second);
		bulidtree.push_back(temp);
	}
	HuffNode *temp1, *temp2, *temp3 = NULL;
	while (bulidtree.size() > 1)
	{
		temp1 = bulidtree[0];
		bulidtree.erase(bulidtree.begin());
		temp2 = bulidtree[0];
		temp3 = new IntlNode(temp1, temp2);
		//cout << (int)temp1->getch() << ":" << temp1->weight() << " " << (int)temp2->getch() << ":" << temp2->weight() << " " << temp3->weight()<<endl;
		bulidtree[0] = temp3;
		sort(bulidtree.begin(), bulidtree.end(), heapsort);
	}
	//test(temp3);
	return temp3;
}
void recursion_encodeing(HuffNode* root, string code, map<char, string> &chencode)
{
	if (root == NULL)
		return;
	if (root->isLeaf())
		chencode[root->getch()] = code;
	recursion_encodeing(root->getleft(), code + "0", chencode);
	recursion_encodeing(root->getright(), code + "1", chencode);

}

string encode()
{
	HuffNode* root = bulidHuffman();
	string code;
	recursion_encodeing(root, code, chencode);
	code.clear();
	for (int i = 0; i < text.size(); i++)
	{
		code += chencode[text[i]];
		//cout << chencode[text[i]]<<endl;
	}
	
	for (auto it = chencode.begin(); it != chencode.end(); it++)
	{
		cout << it->first << ":" << it->second<<endl;
	}
	
	//cout << endl;

	return code;

}
string decode()
{
	string temp;
	string oritext;
	for (int i = 0; i < text.size(); i++)
	{
		temp += text[i];
		//cout << temp << endl;
		auto it = decodetable.find(temp);
		if (it != decodetable.end())
		{
			oritext += it->second;
			temp.clear();
		}
	}
	//cout << oritext;
	return oritext;
}


string changetoHuffmanCode(string code)
{
	string encode;
	int leave = code.size() % 8;
	wirtezero = 0;
	for (int i = 0; i < 8 - leave; i++)
	{
		code += "0";
		wirtezero++;
	}
	textsize = code.size() / 8;
	for (int i = 0; i < code.size() / 8; i++)
	{
		unsigned char eachdecode = 0;
		for (int j = 0; j < 8; j++)
		{
			if (code[i * 8 + j] == '1')
				eachdecode += pow(2, 8 - j - 1);
		}
		//cout << code<<" "<<eachdecode<<endl;
		encode += eachdecode;
	}

	return encode;
}

void outputencodefile(string file)
{
	string code = encode();
	ofstream outfile(file);

	//cout << code<<endl;
	code = changetoHuffmanCode(code);
	unsigned char textwirtezero = wirtezero;
	outfile << "|{";
	outfile << chsize << " " << textsize;
	string letter;
	string encodetable;
	for (auto it = chencode.begin(); it != chencode.end(); it++)
	{
		letter = it->first;
		//cout << it->second << endl;
		encodetable = changetoHuffmanCode(it->second);
		outfile << letter;
		outfile << encodetable;
		outfile << wirtezero;
		outfile << NULL;
	}
	outfile << code;
	outfile << textwirtezero;
}
void outputdecodefile(string file)
{
	string code = decode();
	ofstream outfile(file);
	outfile << code;
}

void menu()
{
	char choice = 'a';

	cout << "Welcome to the HuffmanCode." << endl;

	do {
		choice = 'a';
		cout << "What would you like to do?" << endl;
		cout << "\t1. Encode" << endl;
		cout << "\t2. Decode" << endl;
		cout << "\t0. exit" << endl;
		cout << "your choice ---" << endl;
		cin >> choice;
		int ch;
		string filename;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (choice)
		{
		case '1':
			cout << "Please enter your encode file name:";
			cin >> filename;
			getchar();
			readEncodefile(filename);
			cout << "Please enter your the output file name:";
			filename.clear();
			cin >> filename;
			outputencodefile(filename);
			getchar();
			cout << "Succeeful encode this file and loacte in " << filename << endl;
			filename.clear();
			fflush(stdin);
			break;
		case '2':
			cout << "Please enter your decode file name:";
			cin >> filename;
			getchar();
			readDecodefile(filename);
			cout << "Please enter your the output file name:";
			filename.clear();
			cin >> filename;
			outputdecodefile(filename);
			getchar();
			cout << "Succeeful decode this file and loacte in " << filename << endl;
			filename.clear();
			fflush(stdin);
			break;
		default:
			system("CLS");
			fflush(stdin);
			break;
		}
	} while (choice != '0');
	system("pause");

}

int main()
{
	menu();
	system("pause");

}
