// Copyright 2020 elizavetamaikova
#include "Student.hpp"

void Student::print_hor(){
  uint32_t size_s = 2;
  std::string ver = "|";
  std::string hor = "-";
  _out += ver;
  for (uint32_t i = 0;
       i < _student_size[0] + size_s;
       i++) _out += hor;
  _out += ver;
  for (uint32_t i = 0;
       i < _student_size[1] + size_s;
       i++) _out += hor;
  _out += ver;
  for (uint32_t i = 0;
       i < _student_size[2] + size_s;
       i++) _out += hor;
  _out += ver;
  for (uint32_t i = 0;
       i < _student_size[3] + size_s;
       i++) _out += hor;
  _out += ver + '\n';
}


Student::Student() {
  _student_size[0] = 4;
  _student_size[1] = 4;
  _student_size[2] = 4;
  _student_size[3] = 4;
  _out = "";
  _students.clear();
}
Student::~Student() {
  _students.clear();
}

void Student::from_json(const json& j, student_inf& st){
  get_name(j.at("name"), st);
  get_group(j.at("group"), st);
  get_avg(j.at("avg"), st);
  get_debt(j.at("debt"), st);
}

void Student::get_name(const json& j, student_inf& st){
  st.name = j.get<std::string>();
}

void Student::get_debt(const json& j, student_inf& st){
  if (j.is_null()) {
    st.debt.push_back(nullptr);
  } else if (j.is_string()) {
    st.debt.push_back(j.get<std::string>());
  } else if (j.is_array()) {
    for (json::const_iterator it = j.cbegin(); it != j.cend(); ++it)
      st.debt.push_back(it->get<std::string>());
  }
}

void Student::get_avg(const json& j, student_inf& st){
  if (j.is_null())
    st.debt.push_back(nullptr);
  else if (j.is_string())
    st.avg = j.get<std::string>();
  else if (j.is_number_float())
    st.avg = j.get<double>();
  else
    st.avg = j.get<std::size_t>();
}

void Student::get_group(const json& j, student_inf& st){
  if (j.is_string())
    st.group = j.get<std::string>();
  else
    st.group = j.get<std::size_t>();
}

uint32_t Student::get_name_length(const student_inf& st) {
  return static_cast<uint32_t>(st.name.length());
}

uint32_t Student::get_group_length(const student_inf& st) {
  if (st.group.type() == typeid(std::string))
    return static_cast<uint32_t>(\
            std::any_cast<std::string>(st.group).length());
  else if (st.group.type() == typeid(int))
    return static_cast<uint32_t>(\
            std::to_string(std::any_cast<int>(st.group)).length());
  else
    return 0;
}

uint32_t Student::get_avg_length(const student_inf& st){
  uint32_t n = 0;
  if (st.avg.type() == typeid(int)) {
    return static_cast<uint32_t>(\
            std::to_string(std::any_cast<int>(st.avg)).length());
  } else if (st.avg.type() == typeid(float)) {
    return static_cast<uint32_t>(\
            std::to_string(std::any_cast<float>(st.avg)).length());
  } else if (st.avg.type() == typeid(std::string)) {
    return static_cast<uint32_t>(\
            std::any_cast<std::string>(st.avg).length());
  } else {
    return n;
  }
}

uint32_t Student::get_debt_length(const student_inf& st){
  uint32_t nullptr_size = 4;
  uint32_t null_size = 0;
  uint32_t array_size = 6;
  if (st.debt.size() == 1 && st.debt[0].type() == typeid(std::nullptr_t))
    return nullptr_size;
  else if (st.debt.size() == 1 && st.debt[0].type() == typeid(std::string))
    return std::any_cast<std::string>(st.debt[0]).length();
  else if (st.debt.size() == 0) return null_size;
  else
    return std::to_string(st.debt.size()).length() + array_size;
}

void Student::print_name(const student_inf& st){
  uint32_t s_p = 1;
  std::string ver = "|";
  std::string hor = "-";
  _out += ver + " ";
  _out += st.name;
  uint32_t sp = _student_size[0] - st.name.length() + s_p;
  for (uint32_t i = 0;
       i < sp;
       i++) _out += " ";
}

void Student::print_group(const student_inf& st) {
  uint32_t s_p = 1;
  std::string ver = "|";
  std::string hor = "-";
  _out += ver + " ";
  if (st.group.type() == typeid(std::string))
  {
    _out += std::any_cast<std::string>(st.group);
    uint32_t sp = _student_size[1];
    sp = sp - std::any_cast<std::string>(st.group).length() + s_p;
    for (uint32_t i = 0;
         i < sp;
         i++) _out += " ";
  } else if (st.group.type() == typeid(size_t)) {
    std::string group;
    group = std::to_string(std::any_cast<size_t>(st.group));
    _out += group;
    uint32_t sp = _student_size[1] - group.length() + s_p;
    for (uint32_t i = 0; i < sp; i++) _out += " ";
  }
}

void Student::print_avg(const student_inf& st) {
  uint32_t s_p = 1;
  std::string ver = "|";
  std::string hor = "-";
  _out += ver + " ";
  if (st.avg.type() == typeid(std::string))
  {
    _out += std::any_cast<std::string>(st.avg);
    uint32_t sp = _student_size[2];
    sp = sp - std::any_cast<std::string>(st.avg).length() + s_p;
    for (uint32_t i = 0;
         i < sp;
         i++) _out += " ";
  } else if (st.avg.type() == typeid(size_t)) {
    std::string avg;
    avg = std::to_string(std::any_cast<size_t>(st.avg));
    _out += avg;
    uint32_t sp = _student_size[2] - avg.length() + s_p;
    for (uint32_t i = 0; i < sp; i++) _out += " ";
  } else if (st.avg.type() == typeid(double)) {
    std::ostringstream avg_pr;
    avg_pr << std::fixed;
    avg_pr << std::setprecision(2);
    avg_pr << std::any_cast<double>(st.avg);
    std::string avg = avg_pr.str();
    _out += avg;
    uint32_t sp = _student_size[2] - avg.length() + s_p;
    for (uint32_t i = 0; i < sp; i++) _out += " ";
  }
}

void Student::print_debt(const student_inf& st) {
  uint32_t s_p = 1;
  uint32_t null_size = 3;
  uint32_t s_p_items = 5;
  std::string ver = "|";
  std::string hor = "-";
  _out += ver + " ";
  if (st.debt.size() == 1 && st.debt[0].type() == typeid(nullptr)){
    _out += "null";
    uint32_t sp = _student_size[3] - null_size;
    for (uint32_t i = 0; i < sp; i++) _out += " ";
  } else if (st.debt.size() == 1 && st.debt[0].type() == typeid(std::string)){
    std::string debt = std::any_cast<std::string>(st.debt[0]);
    uint32_t sp = _student_size[3] - debt.length() + s_p;
    _out += debt;
    for (uint32_t i = 0; i < sp; i++) _out += " ";
  } else if (st.debt.size() > 1){
    _out = _out + std::to_string(st.debt.size()) + " items";
    uint32_t sp = _student_size[3];
    sp = sp - std::to_string(st.debt.size()).length() - s_p_items;
    for (uint32_t i = 0; i < sp; i++) _out += " ";
  }
  _out += ver + '\n';
}


void Student::push_student(const student_inf& st) {
  _students.push_back(st);
}

void Student::push_size(const student_inf& st) {
  if (get_name_length(st) > _student_size[0])
    _student_size[0] = get_name_length(st);
  if (get_group_length(st) > _student_size[1])
    _student_size[1] = get_group_length(st);
  if (get_avg_length(st) > _student_size[2])
    _student_size[2] = get_avg_length(st);
  if (get_debt_length(st) > _student_size[3])
    _student_size[3] = get_debt_length(st);
}

void Student::parse_string(const std::string& str) {
  json j = json::parse(str);
  if (!j.at("items").is_array()) throw std::runtime_error("Not array");
  if (j.at("items").size() != j.at("_meta").at("count").get<size_t>())
    throw std::runtime_error("Invalid _meta count");
  student_inf st;
  for (json::const_iterator it = j.at("items").cbegin();\
                            it != j.at("items").cend();\
                          ++it){
    from_json(it.value(), st);
    push_student(st);
    push_size(st);
    st.debt.clear();
  }
}

void Student::parse_file(const std::string& path) {
  std::ifstream input_file;
  input_file.open(path, std::ios::in);
  if (!input_file.is_open())
    throw std::runtime_error("File error");
  std::string string;
  input_file >> string;
  input_file.close();
  //std::cout << string << std::endl;
  parse_string(string);
}

void Student::print_table() {
  uint32_t n = 3;
  uint32_t g = 4;
  uint32_t a = 2;
  uint32_t d = 3;
  std::string ver = "|";
  std::string hor = "-";
  _out += ver;
  _out += " name";
  for (uint32_t i = 0;
       i < _student_size[0] - n;
       i++) _out += " ";
  _out += ver;
  _out += " group";
  for (uint32_t i = 0;
       i < _student_size[1] - g;
       i++) _out += " ";
  _out += ver;
  _out += " avg";
  for (uint32_t i = 0;
       i < _student_size[2] - a;
       i++) _out += " ";
  _out += ver;
  _out += " debt";
  for (uint32_t i = 0;
       i < _student_size[3] - d;
       i++) _out += " ";
  _out = _out + ver + '\n';
  print_hor();

  for (uint32_t i = 0;
       i < _students.size();
       i++){
    print_name(_students[i]);
    print_group(_students[i]);
    print_avg(_students[i]);
    print_debt(_students[i]);
    print_hor();
  }
}

std::string Student::ret_string() {
  return _out;
}

std::ostream& operator<<(std::ostream &out, Student& _student) {
  _student.print_table();
  out<<_student._out;
return out;
}
