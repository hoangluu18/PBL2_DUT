#include "movieManagement.h"
#include "suatchieu.h"
#include <conio.h>
#include "accManagement.h"

movieManagement::movieManagement() {}

movieManagement::~movieManagement() {}

void movieManagement::printMovie(string movieId)
{
    node<movie> *current = this->head;

    while (current != NULL)
    {
        if (current->data.getId() == movieId)
        {
            // Tìm thấy phim với ID tương ứng, in thông tin phim này
            cout << "\t\t\t+----------+-------------------------+----------------------+--------+---------+------+\n";
            cout << "\t\t\t|   MA     |       TEN PHIM          |       THE LOAI      | DODAI  | DO TUOI | NAM  |\n";
            cout << "\t\t\t+----------+-------------------------+----------------------+--------+---------+------+\n";
            cout << "\t\t\t| " << setw(8) << setfill(' ') << left << current->data.getId() << " | ";
            cout << setw(24) << setfill(' ') << left << current->data.getTitle() << " | ";
            cout << setw(20) << setfill(' ') << left << current->data.getGenre() << " | ";
            cout << setw(6) << setfill(' ') << left << current->data.getLenght() << " | ";
            cout << setw(7) << setfill(' ') << left << current->data.getAge() << " | ";
            cout << setw(4) << setfill(' ') << left << current->data.getYear() << " | ";
            cout << "\n\t\t\t+----------+-------------------------+----------------------+--------+---------+------+\n";
            return;  // Khi đã tìm thấy phim, thoát khỏi hàm
        }
        current = current->next;
    }

    // Nếu không tìm thấy phim với ID tương ứng
    cout << "Khong tim thay phim voi ID: " << movieId << endl;
}

void movieManagement::addMovie(movie newMovie)
{
    this->insert(newMovie);
}

bool movieManagement::removeMovie(string id)
{
    movie *m = this->search(id);
    if (m == NULL)
    {
        cout << "\nnot found , check again : ";
        return false;
    }

    this->remove(*m);
    return true;
}

bool movieManagement::editMovie(string id)
{
    movie *m = this->search(id);
    if (m == NULL)
    {
        cout << "\nnot found check again : \n";
        return false;
    }

    this->edit(*m);
    return true;
}

void movieManagement::readFile()
{
    ifstream file;

    file.open("Movie_information.txt");

    if (!file.is_open())
    {
        cout << "can not open file, check again\n";
    }
    // id,title,genre,lenght,age,year
    else
    {
        string line;
        movie token;
        int pos;

        try
        {
            while (getline(file, line))
            {
                pos = line.find(';');

                token.setId(line.substr(0, pos));

                line.erase(0, pos + 1);

                pos = line.find(';');

                token.setTitle(line.substr(0, pos));

                line.erase(0, pos + 1);

                pos = line.find(';');

                token.setGenre(line.substr(0, pos));

                line.erase(0, pos + 1);

                pos = line.find(';');

                token.setLenght(stoi(line.substr(0, pos)));

                line.erase(0, pos + 1);

                pos = line.find(';');

                token.setAge(line.substr(0, pos));

                line.erase(0, pos + 1);

                token.setYear(stoi(line));

                this->addMovie(token);
            }
        }
        catch (const std::exception &e)
        {
            cout << "error: " << e.what() << endl;
            cout << "check again file\n";
        }
    }
    file.close();
}

void movieManagement::writeFile()
{
    ofstream file;
    file.open("Movie_information.txt");
    if (!file.is_open())
    {
        cout << "can not open file, check again\n";
    }
    else
    {
        node<movie> *current = this->head;
        while (current != NULL)
        {
            file << current->data.getId() << ";" << current->data.getTitle() << ";" << current->data.getGenre() << ";" << current->data.getLenght() << ";" << current->data.getAge() << ";" << current->data.getYear() << endl;

            current = current->next;
        }

        file.close();
    }
}

void movieManagement::printListMovies()
{
    node<movie> *current = this->head;
    int widthTable = this->size;
    int count = 0;
    string table[widthTable][6];

    while (current != NULL)
    {

        table[count][0] = current->data.getId();
        table[count][1] = current->data.getTitle();
        table[count][2] = current->data.getGenre();
        table[count][3] = to_string(current->data.getLenght());
        table[count][4] = current->data.getAge();
        table[count][5] = to_string(current->data.getYear());
        count++;
        current = current->next;
    }

    int width[6] = {0};
    // Duyệt qua mảng 2 chiều để tính độ rộng của mỗi cột
    for (int i = 0; i < widthTable; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (table[i][j].length() > width[j])
            {
                width[j] = table[i][j].length();
            }
        }
    }
    // In ra dòng ngăn cách trên cùng của khung
    cout << "\t\t\t+";
    for (int j = 0; j < 6; j++)
    {
        cout << setw(width[j] + 2) << setfill('-') << "-";
        cout << "+";
    }
    cout << endl;
    // In ra tiêu đề của bảng
    cout << "\t\t\t|";
    cout << setw(width[0] + 2) << setfill(' ') << left << "MA"
         << "|";
    cout << setw(width[1] + 2) << setfill(' ') << left << "TEN PHIM"
         << "|";
    cout << setw(width[2] + 2) << setfill(' ') << left << "THE LOAI"
         << "|";
    cout << setw(width[3] + 2) << setfill(' ') << left << "DODAI"
         << "|";
    cout << setw(width[4] + 2) << setfill(' ') << left << "DO TUOI"
         << "|";
    cout << setw(width[5] + 2) << setfill(' ') << left << "NAM"
         << "|";
    cout << endl;

    // In ra nội dung của bảng
    for (int i = 0; i < widthTable; i++)
    {
        cout << "\t\t\t|";
        for (int j = 0; j < 6; j++)
        {
            cout << setw(width[j] + 2) << setfill(' ') << left << table[i][j] << "|";
        }
        cout << endl;
    }

    // In ra dòng ngăn cách dưới cùng của khung
    cout << "\t\t\t+";
    for (int j = 0; j < 6; j++)
    {
        cout << setw(width[j] + 2) << setfill('-') << "-";
        // In ra dấu "+"
        cout << "+";
    }
    cout << endl;
}

bool movieManagement::checkPrimarykey(string id)
{
    node<movie> *current = this->head;

    while (current != NULL)
    {
        if (current->data.getId() == id)
        {
            return false; // nếu trùng khóa chính trả về false
        }
        current = current->next;
    }
    return true;
}

void movieManagement::startManager()
{
    system("cls");
    this->readFile();
    char tt;

    do
    {

        this->printListMovies();
        cout << "\t\t\t1. add movie\n";
        cout << "\t\t\t2. remove movie\n";
        cout << "\t\t\t3. edit movie\n";
        cout << "\t\t\t4. list movie\n";
        cout << "\t\t\t5. exit\n";
        cout << "\t\t\tChoose: ";

        tt = getche();

        switch (tt)
        {
        case '1':
        {
            movie new_movie;
            cout << endl;
            cin >> new_movie;

            while (this->checkPrimarykey(new_movie.getId()) != true)
            {
                string newId;
                cout << "\nprimary key is exist , retype \n";
                cin >> newId;
                new_movie.setId(newId);
            }
            this->addMovie(new_movie);
            this->writeFile();
            break;
        }
        case '2':
        {
            string id;
            cout << "\nmovie id : ";
            cin >> id;
            while (this->removeMovie(id) != true)
            {
                cin >> id;
                continue;
            }
            this->writeFile();
            break;
        }
        case '3':
        {
            string id;
            cout << "\nmovie id : ";
            cin >> id;
            while (this->editMovie(id) != true)
            {
                cin >> id;
                continue;
            }
            this->writeFile();
            break;
        }
        case '4':
        {
            cout << "\n";
            system("cls");
            this->printListMovies();
            cout << "\t\t\tpress any key to continue";
            getch();
            break;
        }
        case '5':
        {
            accManagement acc;
	        acc.checkLogin();
            return;
        }
        default:
            cout << "\a";
        }
        system("cls");

    } while (tt != 5);
    
}

void movieManagement::startStaff()
{
    system("cls");
    this->readFile();
    std::string tt; // Sử dụng kiểu string thay cho char

    while (true)
    {
        system("cls");
        std::cout << "\t\t\tLIST MOVIE" << std::endl;
        this->printListMovies();
        std::cout << "\t\t\tChoose the FilmKey: ";
        cin >> tt; // Đọc một phím mà không cần nhấn Enter
        movieManagement::printMovie(tt);

        std::cout << "* Nhan 1 de chon lai hoac nhan phim bat ky de thoat *" << std::endl;

        char choice = getch(); // Đọc ký tự để kiểm tra tiếp tục hoặc thoát

        if (choice != '1') {
            break;  // Thoát khỏi vòng lặp nếu không nhập '1'
        }
    }
    accManagement acc;
	acc.checkLogin();
}
