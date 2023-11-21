#include <iostream>
#include <string>
using namespace std;

#define MAX 1000 //最大人数

struct Person
{
    string m_Name;//姓名
    int m_Sex;//性别: 1男 2女
    int m_Age;//年龄
    string m_Phone; //电话
    string m_Addr;//住址
};

struct Addressbooks {
    //保存联系人的数组
    struct Person personArray[MAX];
    //联系人个数
    int m_Size;
};

//显示菜单
void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

//添加联系人
void addPerson(Addressbooks* abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        //姓名
        cout << "请输入姓名：" << endl;
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男 ：" << endl;
        cout << "2 --- 女 ：" << endl;
        int sex;

        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "性别不合法，请重新输入" << endl;
            }
        }


        //年龄
        cout << "请输入年龄：" << endl;
        int age;
        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            else
            {
                cout << "年龄不合法，请重新输入" << endl;
            }
        }


        //电话
        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;


        //地址
        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //跟新人数
        abs->m_Size++;

        cout << "添加成功" << endl;
        system("pause"); //请按任意键继续
        system("cls"); //清屏
    }
}

//显示所有联系人
void showPerson(Addressbooks* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前的记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

//检测联系人是否存在
//return: 不存在返回-1，存在返回index位置
int isExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
    cout << "请输入要删除联系人姓名：" << endl;
    string name;
    cin >> name;

    int indexPerson = 0;
    indexPerson = isExist(abs, name);
    if (indexPerson != -1)
    {
        for (int i = indexPerson; i < abs->m_Size; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
    cout << "请输入要查找联系人姓名：" << endl;
    string name;
    cin >> name;

    int indexPerson = 0;
    indexPerson = isExist(abs, name);
    if (indexPerson != -1)
    {
        cout << "姓名：" << abs->personArray[indexPerson].m_Name << "\t";
        cout << "性别：" << (abs->personArray[indexPerson].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[indexPerson].m_Age << "\t";
        cout << "电话：" << abs->personArray[indexPerson].m_Phone << "\t";
        cout << "住址：" << abs->personArray[indexPerson].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
    cout << "请输入要修改联系人姓名：" << endl;
    string name;
    cin >> name;

    int indexPerson = 0;
    indexPerson = isExist(abs, name);
    if (indexPerson != -1)
    {
        cout << "请输入姓名：" << endl;
        cin >> abs->personArray[indexPerson].m_Name;

        cout << "请输入性别：" << endl;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男 ：" << endl;
        cout << "2 --- 女 ：" << endl;
        int sex;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "性别不合法，请重新输入" << endl;
            }
        }
        abs->personArray[indexPerson].m_Sex = sex;

        cout << "请输入年龄：" << endl;
        int age;
        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            else
            {
                cout << "年龄不合法，请重新输入" << endl;
            }
        }
        abs->personArray[indexPerson].m_Age = age;

        cout << "请输入电话：" << endl;
        cin >> abs->personArray[indexPerson].m_Phone;

        cout << "请输入地址：" << endl;
        cin >> abs->personArray[indexPerson].m_Addr;

        cout << "修改成功" << endl;

        system("pause");
        system("cls");
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

//清空联系人(逻辑清空)
void clearPerson(Addressbooks* abs)
{
    cout << "清空联系人" << endl;
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}

int main()
{
    int select = 0;

    //创建通讯录结果提变量
    Addressbooks abs;
    abs.m_Size = 0;


    while (true)
    {
        showMenu();
        cin >> select;

        switch (select)
        {
        case 1:
        {
            //添加联系人
            addPerson(&abs);
            break;
        }
        case 2:
        {
            //显示所有联系人
            showPerson(&abs);
            break;
        }
        case 3:
        {
            //删除联系人
            deletePerson(&abs);
            break;
        }
        case 4:
        {
            //查找联系人
            findPerson(&abs);
            break;
        }
        case 5:
        {
            //修改联系人
            modifyPerson(&abs);
            break;
        }
        case 6:
        {
            //清空联系人
            clearPerson(&abs);
            break;
        }
        case 0:
        {
            //退出通讯录
            cout << "欢迎下次使用" << endl;
            cin.get();
            return 0;
            break;
        }
        default:
        {
            break;
        }
        }
    }

    cin.get();
    return 0;
}