#include <iostream>
#include<string>

#define MAX 1000

using namespace std;


struct Person {
    string name;
    string sex;
    int age = 0;
    string phoneNumber;
    string address;
};


struct AddressList {
    Person personArray[MAX];
    int size = 0;
};


//�����ϵ��
void addPerson(AddressList *address_list) {
    if (address_list->size == MAX) {
        return;
    }

    // �������
    string name;
    cout << "������������" << endl;
    cin >> name;
    address_list->personArray[address_list->size].name = name;

    //����Ա�
    cout << "�������Ա�" << endl;
    string sex;
    cin >> sex;
    address_list->personArray[address_list->size].sex = sex;

    //�������
    cout << "���������䣺" << endl;
    int age;
    cin >> age;
    address_list->personArray[address_list->size].age = age;

    //��ӵ绰����
    cout << "����绰���룺" << endl;
    string number;
    cin >> number;
    address_list->personArray[address_list->size].phoneNumber = number;

    //��ӵ�ַ
    cout << "�������ַ��" << endl;
    string address;
    cin >> address;
    address_list->personArray[address_list->size].address = address;

    //��������
    address_list->size++;
    cout << "��ӳɹ�" << endl;
}

//��ʾ��ϵ��
void showPerson(const AddressList *address_list) {
    if (address_list->size == 0) {
        cout << "��ǰ��¼Ϊ��" << endl;
    } else {
        for (int i = 0; i < address_list->size; i++) {
            Person person = address_list->personArray[i];
            cout << "������" << person.name << "\t";
            cout << "�Ա�" << person.sex << "\t";
            cout << "���䣺" << person.age << "\t";
            cout << "�绰��" << person.phoneNumber << "\t";
            cout << "��ַ��" << person.address << endl;
        }
    }
}

// ��ʾ�˵�ҳ��
void showMenu() {
    cout << "*************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "*************************" << endl;
}

int main() {
    AddressList address_list;


    int select;
    while (true) {
        //��ʾ�˵�
        showMenu();

        cin >> select;

        switch (select) {
            case 1: //1�������ϵ��
                addPerson(&address_list);
                break;
            case 2: //2����ʾ��ϵ��
                showPerson(&address_list);
                break;;
            case 3: //3��ɾ����ϵ��
                break;
            case 4: //4��������ϵ��
                break;
            case 5: //5���޸���ϵ��
                break;
            case 6: //6�������ϵ��
                break;
            case 0: //0���˳�ͨѶ¼
                cout << "Thankyou" << endl;
                return 0;
            default:
                break;
        }
    }
}
