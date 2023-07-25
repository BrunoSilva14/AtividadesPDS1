#include "google_password.h"

#include <iostream>

using namespace std;

bool espacoEmBranco(string password) {
  for (char c : password) {
    if (c==' ') return true;
  }

  return false;
}

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  if (validPassword(password)){
    if (passwords_.find(url) != passwords_.end()) return;
    Usuario user{login, password};
    passwords_[url] = user;
}
}

void GooglePassword::remove(const std::string& url) {
  passwords_.erase(url);
}

void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  if (passwords_.find(url) == passwords_.end()){
    return;
  }

  Usuario user = passwords_[url];

  if (user.password != old_password){
    return;
  }

  if (!validPassword(new_password)) {
    return;
  }
 Usuario usuario{login,new_password};
  passwords_[url] = usuario;
}

void GooglePassword::printPasswords() {
  cout << passwords_.size() << endl;

  map<string, Usuario>::iterator it = passwords_.begin();
  while (it != passwords_.end()) {
    string site = it->first;
    Usuario usuario = it->second;

    cout << site << ": " << usuario.login << " and " << usuario.password << endl;

    ++it;
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
return ((password.find("123456") == std::string::npos) && !(espacoEmBranco(password)) && (password.size() >= 6) && (password.size() <= 50));
}
