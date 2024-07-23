#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//设计联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;//1 男 2 女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person PersonArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};

//1、添加联系人功能
void AddPerson(Addressbooks *abs)
{
	//判断通讯录是否满了
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		printf("请输入姓名：");
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别："<< endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系人电话：" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

//2、显示所有联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录人数是否为0
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "姓名：" << abs->PersonArray[i].m_Name << "\t";
			cout << "性别：" << (abs->PersonArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->PersonArray[i].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[i]. m_Phone<< "\t";
			cout << "住址：" << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断联系人是否存在
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0;i < abs->m_Size;i++)
	{
		//找到用户输入的姓名
		if (abs->PersonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//3、删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret;i < abs->m_Size;i++)
		{
			//数据迁移实现删除
			abs->PersonArray[i] = abs->PersonArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout << "删除成功";
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}
//4、查找指定联系人信息
void findPerson(Addressbooks *abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->PersonArray[ret].m_Name << "\t";
		cout << "性别：" << abs->PersonArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->PersonArray[ret].m_Age << "\t";
		cout << "电话：" << abs->PersonArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->PersonArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人";
	}

	system("pause");
	system("cls");
}

//5、修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系人电话：" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		cout << "查无此人" << endl;

		system("pause");
		system("cls");

	}
	else
	{
		cout << "查无此人" << endl;
	}
}
//6、清空所有联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;

	system("pause");
	system("cls");
}
//封装函数显示菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出联系人  *****" << endl;
	cout << "**************************" << endl;
}
int main() 
{
	Addressbooks abs; //通讯录结构体变量
	abs.m_Size = 0; //初始化

	int select = 0;//创建用户选择输入的变量
	while (true) 
	{
		//调用菜单
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  //添加联系人
			AddPerson(&abs); //利用地址传递，可以修改实参
			break;
		case 2:  //显示联系人
			showPerson(&abs);
			break;
		case 3:  //删除联系人
		//{	cout << "请输入删除联系人的姓名：";
		//string name;
		//cin >> name;
		//if (isExist(&abs, name) == -1)
		//{
		//	cout << "查无此人" << endl;
		//}
		//else
		//{
		//	cout << "找到此人" << endl;
		//}
		//}
			deletePerson(&abs);
			break;
		case 4:  //查找联系人
			findPerson(&abs);
			break;
		case 5:  //修改联系人
			modifyPerson(&abs);
			break;
		case 6:  //清空联系人
			cleanPerson(&abs);
			break;
		case 0:  //退出联系人
			cout << "欢迎下次使用系统" << endl;
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