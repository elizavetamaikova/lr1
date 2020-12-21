// Copyright 2020 elizavetamaikova
#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <vector>
#include "serializer.hpp"
#include <any>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>
using nlohmann::json;

struct student_inf{
  std::string name;
  std::any group;
  std::any avg;
  std::vector<std::any> debt;
};

class Student {
 public:
  Student();
  ~Student();
  void parse_string(const std::string& str);
  void parse_file(const std::string& path);
  void from_json(const json& j, student_inf& st);
  void get_name(const json& j, student_inf& st);
  void get_debt(const json& j, student_inf& st);
  void get_avg(const json& j, student_inf& st);
  void get_group(const json& j, student_inf& st);
  void print_name(const student_inf& st);
  void print_group(const student_inf& st);
  void print_avg(const student_inf& st);
  void print_debt(const student_inf& st);
  uint32_t get_name_length(const student_inf& st);
  uint32_t get_group_length(const student_inf& st);
  uint32_t get_avg_length(const student_inf& st);
  uint32_t get_debt_length(const student_inf& st);
  void push_student(const student_inf& st);
  void push_size(const student_inf& st);
  void print_table();
  void print_hor();
  std::string ret_string();
  friend std::ostream& operator << (std::ostream &out, Student& _student);

 private:
  std::vector<student_inf> _students;
  uint32_t _student_size[4];
  std::string _out;
};
#endif  // INCLUDE_STUDENT_HPP_
