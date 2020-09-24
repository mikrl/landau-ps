#include <cmake_test.hxx>
#include <experiment.hxx>

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h> //POSIX compliant getopt

/* Namespaces */
using namespace std;

void usage(string prog_name){
  cout << "usage: " << prog_name << "\n";
}

enum Geometry{
  EUCLIDEAN,
  CYLINDRICAL,
  SPHERICAL
};

int main(int argc, char **argv) {
  int opt;
  int err_flg = 0;

  SimConfig configuration;
  // Flags for whether the geometry, coordinate system and discretization
  // Are configured

  bool geom_conf = false;
  bool coords_conf = false;
  bool discret_conf = false; 

  
  
  while((opt = getopt(argc, argv, ":g:c:d:o:")) != -1){
    switch(opt){
    case 'g': { // 'g' for geometry
      configuration.geometry = optarg;
      geom_conf = true;
      break;
    }
    case 'c': { // 'c' for coordinates
      vector<float> dim_extents;
      configuration.extent = dim_extents;
      coords_conf = true;
      break;
    }
    case 'd': { // 'd' for discretization
      configuration.discretization = optarg;
      discret_conf = true;
      break;
    }
    case 'o': { // 'o' for output method
      configuration.output = optarg;
      break;
    }
    case ':': {
      
      break;
    }
    case '?': {
      //cerr << format("Unrecognized option '-{}'\n", optopt);
      cerr << "Unrecognized option '-"<< optopt <<"'\n";
      err_flg++;
      break;
    }
    default: {
      //cerr << format("Shouldn't see this! Opt is {}", opt) << "\n";
      cerr << "Shouldn't see this! Opt is {}" << optopt << ")\n";
    }      
    }
  }
  if (not(geom_conf and coords_conf and discret_conf)){
    err_flg++;
  }
  if (err_flg){
    cerr << "Usage: ";
    exit(2);
  }
  
  
  return 0;
}
