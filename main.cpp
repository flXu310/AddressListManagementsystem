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


//添加联系人
void addPerson(AddressList *address_list) {
    if (address_list->size == MAX) {
        return;
    }

    // 添加姓名
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    address_list->personArray[address_list->size].name = name;

    //添加性别
    cout << "请输入性别：" << endl;
    string sex;
    cin >> sex;
    address_list->personArray[address_list->size].sex = sex;

    //添加年龄
    cout << "请输入年龄：" << endl;
    int age;
    cin >> age;
    address_list->personArray[address_list->size].age = age;

    //添加电话号码
    cout << "请输电话号码：" << endl;
    string number;
    cin >> number;
    address_list->personArray[address_list->size].phoneNumber = number;

    //添加地址
    cout << "请输入地址：" << endl;
    string address;
    cin >> address;
    address_list->personArray[address_list->size].address = address;

    //更新人数
    address_list->size++;
    cout << "添加成功" << endl;
}

//显示联系人
void showPerson(const AddressList *address_list) {
    if (address_list->size == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < address_list->size; i++) {
            Person person = address_list->personArray[i];
            cout << "姓名：" << person.name << "\t";
            cout << "性别：" << person.sex << "\t";
            cout << "年龄：" << person.age << "\t";
            cout << "电话：" << person.phoneNumber << "\t";
            cout << "地址：" << person.address << endl;
        }
    }
}

// 显示菜单页面
void showMenu() {
    cout << "*************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "*************************" << endl;
}

int main() {
    AddressList address_list;


    int select;
    while (true) {
        //显示菜单
        showMenu();

        cin >> select;

        switch (select) {
            case 1: //1、添加联系人
                addPerson(&address_list);
                break;
            case 2: //2、显示联系人
                showPerson(&address_list);
                break;;
            case 3: //3、删除联系人
                break;
            case 4: //4、查找联系人
                break;
            case 5: //5、修改联系人
                break;
            case 6: //6、清空联系人
                break;
            case 0: //0、退出通讯录
                cout << "Thankyou" << endl;
                return 0;
            default:
                break;
        }
    }
}
