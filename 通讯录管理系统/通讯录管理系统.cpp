#include <iostream>
#include <string>
using namespace std;

#define MAX 1000 //�������

struct Person
{
    string m_Name;//����
    int m_Sex;//�Ա�: 1�� 2Ů
    int m_Age;//����
    string m_Phone; //�绰
    string m_Addr;//סַ
};

struct Addressbooks {
    //������ϵ�˵�����
    struct Person personArray[MAX];
    //��ϵ�˸���
    int m_Size;
};

//��ʾ�˵�
void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "***************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks* abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷���ӣ�" << endl;
        return;
    }
    else
    {
        //����
        cout << "������������" << endl;
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //�Ա�
        cout << "�������Ա�" << endl;
        cout << "1 --- �� ��" << endl;
        cout << "2 --- Ů ��" << endl;
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
                cout << "�Ա𲻺Ϸ�������������" << endl;
            }
        }


        //����
        cout << "���������䣺" << endl;
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
                cout << "���䲻�Ϸ�������������" << endl;
            }
        }


        //�绰
        cout << "������绰��" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;


        //��ַ
        cout << "�������ַ��" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //��������
        abs->m_Size++;

        cout << "��ӳɹ�" << endl;
        system("pause"); //�밴���������
        system("cls"); //����
    }
}

//��ʾ������ϵ��
void showPerson(Addressbooks* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "��ǰ�ļ�¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "������" << abs->personArray[i].m_Name << "\t";
            cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
            cout << "���䣺" << abs->personArray[i].m_Age << "\t";
            cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
            cout << "סַ��" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

//�����ϵ���Ƿ����
//return: �����ڷ���-1�����ڷ���indexλ��
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

//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
    cout << "������Ҫɾ����ϵ��������" << endl;
    string name;
    cin >> name;

    int indexPerson = 0;
    indexPerson = isExist(abs, name);
    if (indexPerson != -1)
    {
        for (int i = indexPerson; i < abs->m_Size; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs)
{
    cout << "������Ҫ������ϵ��������" << endl;
    string name;
    cin >> name;

    int indexPerson = 0;
    indexPerson = isExist(abs, name);
    if (indexPerson != -1)
    {
        cout << "������" << abs->personArray[indexPerson].m_Name << "\t";
        cout << "�Ա�" << (abs->personArray[indexPerson].m_Sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" << abs->personArray[indexPerson].m_Age << "\t";
        cout << "�绰��" << abs->personArray[indexPerson].m_Phone << "\t";
        cout << "סַ��" << abs->personArray[indexPerson].m_Addr << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
    cout << "������Ҫ�޸���ϵ��������" << endl;
    string name;
    cin >> name;

    int indexPerson = 0;
    indexPerson = isExist(abs, name);
    if (indexPerson != -1)
    {
        cout << "������������" << endl;
        cin >> abs->personArray[indexPerson].m_Name;

        cout << "�������Ա�" << endl;
        cout << "�������Ա�" << endl;
        cout << "1 --- �� ��" << endl;
        cout << "2 --- Ů ��" << endl;
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
                cout << "�Ա𲻺Ϸ�������������" << endl;
            }
        }
        abs->personArray[indexPerson].m_Sex = sex;

        cout << "���������䣺" << endl;
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
                cout << "���䲻�Ϸ�������������" << endl;
            }
        }
        abs->personArray[indexPerson].m_Age = age;

        cout << "������绰��" << endl;
        cin >> abs->personArray[indexPerson].m_Phone;

        cout << "�������ַ��" << endl;
        cin >> abs->personArray[indexPerson].m_Addr;

        cout << "�޸ĳɹ�" << endl;

        system("pause");
        system("cls");
    }
    else
    {
        cout << "���޴���" << endl;
    }
}

//�����ϵ��(�߼����)
void clearPerson(Addressbooks* abs)
{
    cout << "�����ϵ��" << endl;
    abs->m_Size = 0;
    cout << "ͨѶ¼�����" << endl;
    system("pause");
    system("cls");
}

int main()
{
    int select = 0;

    //����ͨѶ¼��������
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
            //�����ϵ��
            addPerson(&abs);
            break;
        }
        case 2:
        {
            //��ʾ������ϵ��
            showPerson(&abs);
            break;
        }
        case 3:
        {
            //ɾ����ϵ��
            deletePerson(&abs);
            break;
        }
        case 4:
        {
            //������ϵ��
            findPerson(&abs);
            break;
        }
        case 5:
        {
            //�޸���ϵ��
            modifyPerson(&abs);
            break;
        }
        case 6:
        {
            //�����ϵ��
            clearPerson(&abs);
            break;
        }
        case 0:
        {
            //�˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
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