#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>

using namespace std;

void intro() 
{
    cout << "\n\t          ";
    cout << "\n占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙";
    cout << "\n\n Sistema de Gestao de Reservas ";
    cout << "\n\n占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙";
}

void head() 
{
    cout <<"\n占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙占쏙옙";
}

void time() 
{
    int c = 0;
    long long j;

    cout << "\n\n\n Conectando ao servidor...";

    while (c < 10) {
        for (j = 5; j > 4; j++) {
            if (j == 99999) {
                cout<<".";
                break;
            }
        }
        ++c;
    }
}

class Hotel 
{
    private:
        int roomNo;
        char name[30];
        char address[50];
        char phone[15];
        int days;
        float fare;
    
    public:
        void mainMenu();
        void add();
        void display();
        void rooms();
        void edit();
        int check(int);
        void modify(int);
        void deleteReservation(int);
};

void Hotel::mainMenu() 
{
    int choice;

    while (choice != 5) {
        system("cls");
        head();
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t   * Menu * ";
        cout << "\n\t\t\t\t *************";
        cout << "\n\n\n\t\t\t 1. Reservar um Quarto";
        cout << "\n\n\n\t\t\t 2. Registro do Cliente";
        cout << "\n\n\n\t\t\t 3. Quartos Reservados";
        cout << "\n\n\n\t\t\t 4. Editar Registro";
        cout << "\n\n\n\t\t\t 5. Sair";
        cout << "\n\n\n\t\t\t Digite sua escolha: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                rooms();
                break;
            case 4:
                edit();
                break;
            case 5:
                break;
            default: 
                {
                    cout << "\n\n\t\t\t OPS! Nao ha esta opção escolhida.";
                    cout << "\n\t\t Pressione qualquer tecla para continuar...!!";

                    getch();
                }
        }
    }
}

void Hotel::add() 
{
    head();

    int r, flag;
    ofstream fout("Record.dat", ios::app);

    cout << "\n Insira os detalhes do cliente";
    cout << "\n -----------------------------";
    cout << "\n\n No. do Quarto: ";
    cin >> r;

    fflush(stdin);
    flag = check(r);

    if (flag) {
        cout << "\n Desculpe..!! Este quarto já esta reservado";
    } else {
        roomNo = r;
        cout << " Nome: ";
        gets(name);
        cout << " Endereco: ";
        gets(address);
        cout << " Telefone: ";
        gets(phone);
        cout << "Informe o número de dias para finalizar a reserva: ";
        cin >> days;

        fare = days * 20;
        fout.write((char*)this,sizeof(Hotel));
        cout << "\n Quarto reservado...!!!";
    }

    cout << "\n Pressione qualque tecla para continuar...!!";
    getch();
    fout.close();
}

void Hotel::display() 
{
    system("cls");
    head();

    ifstream fin("Record.dat", ios::in | ios::binary);
    int r, flag;
    cout << "\n Informe o No. do Quarto: ";
    cin >> r;

    while (fin.read((char*)this,sizeof(Hotel))) {
        if (roomNo == r) {
            head();
            cout << "\n Detalhes do Cliente";
            cout << "\n -------------------";
            cout << "\n\n No. do Quarto: "<< roomNo;
            cout << "\n Nome: "<< name;
            cout << "\n Endereco: "<< address;
            cout << "\n Telefone: "<< phone;
            cout << "\n Dias "<< days;
            cout << "\n Valor Total: "<< fare;

            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "\n Desculpe, este quarto nao foi encontrado ou não esta vago!";
    }

        cout << "\n\n Pressione qualquer tecla para continuar...!!";
        getch();

        fin.close();
}

void Hotel::rooms() 
{
    system("cls");
    head();

    ifstream fin("Record.dat", ios::in | ios::binary);
    cout << "\n\t\t\t Lista de Quartos Ocupados";
    cout << "\n\t\t\t -------------------------";

    while (fin.read((char*)this,sizeof(Hotel))) {
        cout << "\n No. do Quarto: "<< roomNo <<"\n Name: "<< name;
        cout << "\n Endereço: "<< address <<"\n Telefone: "<< phone;
        cout << "\n Dias: "<< days <<"\n Total: "<< fare;
        cout << "\n **********************************";
    }

    cout<< "\n\n\n\t\t\t Pressione qualquer tecla para continuar...!!";
    getch();

    fin.close();
}

void Hotel::edit() 
{
    system("cls");
    head();

    int choice, r;

    cout << "\n Editar Menu";
    cout << "\n ----------";
    cout << "\n\n 1. Modificar Registro do Cliente";
    cout << "\n 2. Excluir Registro do Cliente";
    cout << "\n Informe sua escolha: ";
    cin >> choice;

    system("cls");
    head();

    cout << "\n Informe o No. do Quarto: ";
    cin >> r;

    switch (choice) {
        case 1:
            modify(r);
            break;
        case 2:
            deleteReservation(r);
            break;
        default:
            cout << "\n OPS! Nao há esta opcao escolhida.";
    }

    cout << "Pressione qualquer tecla para continuar...!!";
    getch();
}

int Hotel::check(int r) 
{
    int flag = 0;
    ifstream fin("Record.dat", ios::in);

    while (!fin.eof()) {
        fin.read((char*)this,sizeof(Hotel));

        if (roomNo == r) {
            flag = 1;
            break;
        }
    }

    system("cls");
    fin.close();

    return(flag);
}

void Hotel::modify(int r) 
{
    system("cls");
    head();

    long pos;
    long flag = 0;

    fstream file("Record.dat", ios::in | ios::out | ios::binary);

    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this,sizeof(Hotel));
        fflush(stdin);

        if (roomNo == r) {
            cout << "\n Insira Novos Detalhes";
            cout << "\n ---------------------";
            cout << "\n Nome: ";
            gets(name);
            cout << "Endereco: ";
            gets(address);
            cout << "Telefone: ";
            gets(phone);
            cout << "Dias: ";
            cin >> days;

            fare = days * 900;
            file.seekg(pos);
            file.write((char*)this,sizeof(Hotel));

            cout <<"\n Registro modificado!";

            flag = 1;
            break;
        }
    }

    system("cls");

    if (flag == 0) {
        cout<< "\n Desculpe, este quarto não foi encontrado ou não esta vago!";
    }

    file.close();
}

void Hotel::deleteReservation(int r) 
{
    system("cls");
    head();

    int flag = 0;
    std::string ch;

    ifstream fin("Record.dat", ios::in);
    ofstream fout("temp.dat", ios::out);

    while (!fin.eof()) {
        fin.read((char*)this,sizeof(Hotel));

        if (roomNo == r) {
            cout << "\n Nome: "<< name;
            cout << "\n Endereco: "<< address;
            cout << "\n Telefone: "<< phone;
            cout << "\n Dias: "<< days;
            cout << "\n Valor Total: "<< fare;
            cout << "\n\n Voce deseja excluir este registro(s/n): ";
            cin >> ch;

            if (ch == "n") {
                fout.write((char*)this,sizeof(Hotel));
            }

            flag = 1;
            break;

        } else {
            fout.write((char*)this,sizeof(Hotel));
        }
    }

    system("cls");
    fin.close();
    fout.close();

    if (flag == 0) {
        cout << "\n Desculpe, este quarto não foi encontrado ou não esta vago!";
    } else {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
    }
}

int main() 
{
    Hotel h;

    cout <<"\n\n\n";

    intro();
    time();

    cout << "\n\n\n\t\t\t Pressione qualquer tecla para continuar...!!";

    getch();
    head();

    char id[10], pass[10];

    cout << "\n\n\t\t\t\t Usuario => ";
    cin >> id;
    cout << "\n\t\t\t\t Senha => ";
    cin >> pass;
    cout << "\n\n\t";

    time();

    cout << "\t";

    if (strcmp(id, "admin") == 0 && strcmp(pass, "@admin123") == 0) {
        cout << "\n\n\t\t\t Login realizado com sucesso!";
    } else {
        cout << "\n\n\t\t\t OPS! Login invalido. Verifique o usuario ou senha digitada.";
        getch();
        exit(-1);
    }

    h.mainMenu();
    getch();
    
    return 0;
}