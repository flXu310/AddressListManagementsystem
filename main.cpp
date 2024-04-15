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


//判断联系人是否存在
int is_exist(const AddressList *address_list, const string &name) {
    for (int i = 0; i < address_list->size; i++) {
        Person person = address_list->personArray[i];
        if (person.name == name) {
            return i;
        }
    }

    return -1;
}

//删除指定的联系人
void deletePerson(AddressList *address_list) {
    cout << "请输入你要删除的联系人" << endl;
    string name;
    cin >> name;
    int index = is_exist(address_list, name);
    if (index == -1) {
        cout << "查无此人" << endl;
    } else {
        for (int i = index; i < address_list->size - 1; i++) {
            address_list->personArray[i] = address_list->personArray[i + 1];
        }
        address_list->size--;
        cout << "删除成功" << endl;
    }
}

//查找联系人
void findPerson(const AddressList *address_list) {
    cout << "请输入你要查找的联系人" << endl;
    string name;
    cin >> name;
    int index = is_exist(address_list, name);
    if (index == -1) {
        cout << "查无此人" << endl;
    } else {
        Person person = address_list->personArray[index];
        cout << "姓名：" << person.name << "\t";
        cout << "性别：" << person.sex << "\t";
        cout << "年龄：" << person.age << "\t";
        cout << "电话：" << person.phoneNumber << "\t";
        cout << "地址：" << person.address << endl;
        cout << "查找成功！" << endl;
    }
}

//修改联系人
void modifyPerson(const AddressList *address_list) {
    cout << "请输入你要修改的联系人" << endl;
    string name;
    cin >> name;
    int index = is_exist(address_list, name);
    if (index == -1) {
        cout << "查无此人" << endl;
    } else {
        cout << "不支持修改" << endl;
    }
}

void clearAdddressList(AddressList *address_list) {
    if (address_list->size == 0) {
        cout << "通讯录为空" << endl;
    } else {
        address_list->size = 0;
        cout << "已清空" << endl;
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
    showMenu();

    int select;
    while (true) {
        //显示菜单


        cin >> select;

        switch (select) {
            case 1: //1、添加联系人
                addPerson(&address_list);
                break;
            case 2: //2、显示联系人
                showPerson(&address_list);
                break;;
            case 3: //3、删除联系人
                deletePerson(&address_list);
                break;
            case 4: //4、查找联系人
                findPerson(&address_list);
                break;
            case 5: //5、修改联系人
                modifyPerson(&address_list);
                break;
            case 6: //6、清空联系人
                clearAdddressList(&address_list);
                break;
            case 0: //0、退出通讯录
                cout << "Thankyou！！！" << endl;
                return 0;
            default:
                break;
        }
    }
}
