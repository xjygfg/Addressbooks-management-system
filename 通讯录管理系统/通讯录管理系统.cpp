#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;//1 �� 2 Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person PersonArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

//1�������ϵ�˹���
void AddPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		printf("������������");
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�"<< endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������:" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�˵绰��" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

//2����ʾ������ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�����Ƿ�Ϊ0
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "������" << abs->PersonArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->PersonArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->PersonArray[i].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[i]. m_Phone<< "\t";
			cout << "סַ��" << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�ж���ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0;i < abs->m_Size;i++)
	{
		//�ҵ��û����������
		if (abs->PersonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//3��ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret;i < abs->m_Size;i++)
		{
			//����Ǩ��ʵ��ɾ��
			abs->PersonArray[i] = abs->PersonArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�";
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}
//4������ָ����ϵ����Ϣ
void findPerson(Addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->PersonArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->PersonArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->PersonArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->PersonArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->PersonArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���";
	}

	system("pause");
	system("cls");
}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������:" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�˵绰��" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		cout << "���޴���" << endl;

		system("pause");
		system("cls");

	}
	else
	{
		cout << "���޴���" << endl;
	}
}
//6�����������ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;

	system("pause");
	system("cls");
}
//��װ������ʾ�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳���ϵ��  *****" << endl;
	cout << "**************************" << endl;
}
int main() 
{
	Addressbooks abs; //ͨѶ¼�ṹ�����
	abs.m_Size = 0; //��ʼ��

	int select = 0;//�����û�ѡ������ı���
	while (true) 
	{
		//���ò˵�
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  //�����ϵ��
			AddPerson(&abs); //���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2:  //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  //ɾ����ϵ��
		//{	cout << "������ɾ����ϵ�˵�������";
		//string name;
		//cin >> name;
		//if (isExist(&abs, name) == -1)
		//{
		//	cout << "���޴���" << endl;
		//}
		//else
		//{
		//	cout << "�ҵ�����" << endl;
		//}
		//}
			deletePerson(&abs);
			break;
		case 4:  //������ϵ��
			findPerson(&abs);
			break;
		case 5:  //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:  //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:  //�˳���ϵ��
			cout << "��ӭ�´�ʹ��ϵͳ" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}