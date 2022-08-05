#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "PyroDistPlugin.h"

void PyroDistPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void PyroDistPlugin::run() {}

void PyroDistPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "PyroDist";
myCommand += " ";
myCommand += "-in";
myCommand += " ";
myCommand += parameters["flowfile"];
myCommand += " ";
myCommand += "-rin";
myCommand += " ";
myCommand += parameters["lookupfile"];
myCommand += " ";
myCommand += "-out";
myCommand += " ";
myCommand += outputfile + " ";
std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<PyroDistPlugin> PyroDistPluginProxy = PluginProxy<PyroDistPlugin>("PyroDist", PluginManager::getInstance());
