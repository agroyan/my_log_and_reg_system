#include <iostream>
#include <fstream>
#include "my_exceptions.h"

bool Log_in()
{
  std::string username;
  int password;
  std::cout << "Имя пользователя: ";
  std::getline(std::cin, username);
  if (username.length() < 6)
  {
    Short exc("Ваше имя слишком короткое!");
    throw exc;
  }
  if (username.length() > 15)
  {
    Long exc("Ваше имя слишком длинное!");
    throw exc;
  }
  std::string s_curr = "/Users/jan/Project1/";
  s_curr += username;
  s_curr += ".txt";
  std::ifstream file;
  file.open(s_curr, std::ios::in);
  if (file)
  {
    Unique exc("Это имя пользователя занято");
    file.close();
    throw exc;
  }
  file.close();
  std::cout << "Пароль: ";
  std::cin >> password;
  if (password / 1000 < 1)
  {
    ShortPassword exc("Ваш пароль слишком короткий!");
    throw exc;
  }
  std::string s = "/Users/jan/Project1/";
  s += username;
  s += ".txt";
  std::ofstream new_file;
  new_file.open(s, std::ios::out);
  new_file << username << std::endl << password;
  new_file.close();
  std::cout << "Аккаунт создан!";
  return true;
}

bool Sign_in()
{
  std::string username;
  int password;
  std::cout << "Имя пользователя: ";
  std::getline(std::cin, username);
  std::string s = "/Users/jan/Project1/";
  s += username;
  s += ".txt";
  std::ifstream new_file;
  new_file.open(s, std::ios::in);
  if (new_file)
  {
    std::cout << "Пароль: ";
    std::cin >> password;
    std::string str;
    int x;
    std::getline(new_file, str);
    new_file >> x;
    if (str == username && x == password)
    {
      std::cout << "Вы в системе!!!" << std::endl;
    }
    else
    {
      std::cout << "У вас ошибка в пароле!!!" << std::endl;
      return false;
    }
  }
  else
  {
    std::cout << "У вас ошибка в имени пользователя!!!" << std::endl;
    return false;
  }
  new_file.close();
  return true;
}

bool F()
{
  int n;
  bool res;
  while (true)
    {
        std::cout << "Вы хотите создать новый аккаунт или войти в старый ?" << std::endl;
        std::cout << "Если хотите создать новый, то введите 0" << std::endl;
        std::cout << "Если хотите войти в старый, то введите 1" << std::endl;
        std::cin >> n;
        std::cin.ignore(32767, '\n');
        if (n == 0)
        {
            while (true)
            {
              try
              {
                res = Log_in();
              }
              catch (Short &e)
              {
                std::cout << e.get_s() << std::endl;
                std::cout << "Попробуйте еще раз!" << std::endl;
                std::cout << "" << std::endl;
                continue;
              }
              catch (Long &e)
              {
                std::cout << e.get_s() << std::endl;
                std::cout << "Попробуйте еще раз!" << std::endl;
                std::cout << "" << std::endl;
                continue;
              }
              catch (Unique &e)
              {
                std::cout << e.get_s() << std::endl;
                std::cout << "Попробуйте еще раз!" << std::endl;
                std::cout << "" << std::endl;
                continue;
              }
              catch (ShortPassword &e)
              {
                std::cout << e.get_s() << std::endl;
                std::cout << "Попробуйте еще раз!" << std::endl;
                std::cout << "" << std::endl;
                continue;
              }
              return res;
            }
        }
        else
        {
            if (n == 1)
            {
                res = Sign_in();
                return res;
            }
            else
            {
                std::cout << "Некорректный ввод" << std::endl;
            }
        }
    }
    return true;
}



int main()
{
  F();
}
