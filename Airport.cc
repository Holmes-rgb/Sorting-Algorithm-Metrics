#include "Airport.h"

// Constructor
Airport::Airport() {
  // Set default values to the fields
  OBJECTID = -1;
  the_geom = "NONE";
  Fac_Type = "NONE";
  Field_Office = "NONE";
  State_Name = "NONE";
  County = "NONE";
  City = "NONE";
  Fac_Name = "NONE";
  Fac_Use = "NONE";
  Sectional = "NONE";
  Fuel_Types = "NONE";
  Elevation = -1.0;
  Unicom = -1.0;
  Ctaf = -1.0;
  Atc_Tower = false;
  Landing_Fee = false;
  Wind_Indic = false;
}

Airport::Airport(int OBJECTID, std::string the_geom, std::string Fac_Type,
                 std::string Field_Office, std::string State_Name,
                 std::string County, std::string City, std::string Fac_Name,
                 std::string Fac_Use, std::string Sectional,
                 std::string Fuel_Types, double Elevation, double Unicom,
                 double Ctaf, bool Atc_Tower, bool Landing_Fee,
                 bool Wind_Indic) {
  this->OBJECTID = OBJECTID;
  this->the_geom = the_geom;
  this->Fac_Type = Fac_Type;
  this->Field_Office = Field_Office;
  this->State_Name = State_Name;
  this->County = County;
  this->City = City;
  this->Fac_Name = Fac_Name;
  this->Fac_Use = Fac_Use;
  this->Sectional = Sectional;
  this->Fuel_Types = Fuel_Types;
  this->Elevation = Elevation;
  this->Unicom = Unicom;
  this->Ctaf = Ctaf;
  this->Atc_Tower = Atc_Tower;
  this->Landing_Fee = Landing_Fee;
  this->Wind_Indic = Wind_Indic;
}

std::string Airport::getTheGeom() { return the_geom; }
std::string Airport::getFacType() { return Fac_Type; }
std::string Airport::getFieldOffice() { return Field_Office; }
std::string Airport::getStateName() { return State_Name; }
std::string Airport::getCounty() { return County; }
std::string Airport::getCity() { return City; }
std::string Airport::getFacName() { return Fac_Name; }
std::string Airport::getFacUse() { return Fac_Use; }
std::string Airport::getSectional() { return Sectional; }
std::string Airport::getFuelTypes() { return Fuel_Types; }
int Airport::getObjectid() { return OBJECTID; }
double Airport::getElevation() { return Elevation; }
double Airport::getUnicom() { return Unicom; }
double Airport::getCtaf() { return Ctaf; }
bool Airport::isAtcTower() { return Atc_Tower; }
bool Airport::isLandingFee() { return Landing_Fee; }
bool Airport::isWindIndic() { return Wind_Indic; }

void Airport::setTheGeom(std::string theGeom) { this->the_geom = theGeom; }
void Airport::setFacType(std::string facType) { this->Fac_Type = facType; }
void Airport::setFieldOffice(std::string fieldOffice) {
  this->Field_Office = fieldOffice;
}
void Airport::setStateName(std::string stateName) {
  this->State_Name = stateName;
}
void Airport::setCounty(std::string county) { this->County = county; }
void Airport::setCity(std::string city) { this->City = city; }
void Airport::setFacName(std::string facName) { this->Fac_Name = facName; }
void Airport::setFacUse(std::string facUse) { this->Fac_Use = facUse; }
void Airport::setSectional(std::string sectional) {
  this->Sectional = sectional;
}
void Airport::setFuelTypes(std::string fuelTypes) {
  this->Fuel_Types = fuelTypes;
}
void Airport::setObjectid(int objectid) { this->OBJECTID = objectid; }
void Airport::setElevation(double elevation) { this->Elevation = elevation; }
void Airport::setUnicom(double unicom) { this->Unicom = unicom; }
void Airport::setCtaf(double ctaf) { this->Ctaf = ctaf; }
void Airport::setAtcTower(bool atcTower) { this->Atc_Tower = atcTower; }
void Airport::setLandingFee(bool LandingFee) { this->Landing_Fee = LandingFee; }
void Airport::setWindIndic(bool windIndic) { this->Wind_Indic = windIndic; }

/**
 * Read data into a vector from the downloaded CSV file.
 * Returns true if everything goes well; false otherwise.
 */
bool loadFromFile(std::string fn, std::vector<Airport> &objs) {
  std::ifstream fin;
  fin.open(fn);

  if (!fin) {
    // Bad file / could not open
    return false;
  }

  // Opened file OK

  // Get rid of the header line: read it and throw it away
  std::string header = "";
  getline(fin, header);

  // Declare variables to be used inside the while loop
  int OBJECTID;
  std::string the_geom, Fac_Type, Field_Office, State_Name, County, City,
      Fac_Name, Fac_Use, Sectional, Fuel_Types;
  double Elevation, Unicom, Ctaf;
  bool Atc_Tower, Landing_Fee, Wind_Indic;
  char comma, quote; // This willfin >> comma; come in handy.

  // Read in data while the file is still good
  // and we haven't yet reached the end of file (EOF).
  int counter = 1;

  // was {while (fin && fin.peek() != EOF)}
  while (fin && fin.peek() != EOF) {
    // We initialize variables to sentinel values --
    // values we *know* will not appear in our data.
    // If any object fields have one of these values, we
    // *know* it was incorrectly set.
    OBJECTID = -1;
    the_geom = "NONE";
    Fac_Type = "NONE";
    Field_Office = "NONE";
    State_Name = "NONE";
    County = "NONE";
    City = "NONE";
    Fac_Name = "NONE";
    Fac_Use = "NONE";
    Sectional = "NONE";
    Fuel_Types = "NONE";
    Elevation = -1.0;
    Unicom = -1.0;
    Ctaf = -1.0;
    Atc_Tower = false;
    Landing_Fee = false;
    Wind_Indic = false;
    comma = ',';
    quote = '"';

    // Your input data file will be different. You will have different
    // fields, different values, etc. What follows below may be helpful
    // but you'll need to modify to suit your data.

    // Using the >> (extraction) operator ...
    fin >> OBJECTID; // Expects an int; reads an int.
    if (OBJECTID != counter) {
      std::cout << OBJECTID << " != " << counter << std::endl;
      return false;
    }
    // These read a string; comma is delimiter and is discarded.
    fin >> comma;
    getline(fin, the_geom, ',');
    getline(fin, Fac_Type, ',');
    getline(fin, Field_Office, ',');
    getline(fin, State_Name, ',');
    if (fin.peek() != '"') {
      getline(fin, County, ',');
    } else {
      fin >> quote;
      getline(fin, County, '"');
      fin >> comma;
    }

    if (fin.peek() != '"') {
      getline(fin, City, ',');
    } else {
      fin >> quote;
      getline(fin, City, '"');
      fin >> comma;
    }

    if (fin.peek() != '"') {
      getline(fin, Fac_Name, ',');
    } else {
      fin >> quote;
      getline(fin, Fac_Name, '"');
      fin >> comma;
    }
    getline(fin, Fac_Use, ',');

    if (fin.peek() != comma) {
      if (fin.peek() == 'E') {
        fin.get();
      } else {
        fin >> Elevation;
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      getline(fin, Sectional, ',');
    } else {
      fin >> comma;
    }

    if (fin.peek() != comma) {
      getline(fin, Fuel_Types, ',');
    } else {
      fin >> comma;
    }

    // SS-SR
    if (fin.peek() != comma) {
      if (fin.peek() == 'Y') {
        Atc_Tower = true;
      }
      while (fin.peek() != comma) {
        fin.get();
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      if (fin.peek() == 'N') {
        fin.get();
      } else if (fin.peek() == 'Y') {
        fin.get();
      } else {
        fin >> Unicom;
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      if (fin.peek() == 'N') {
        fin.get();
      } else if (fin.peek() == 'y') {
        fin.get();
      } else {
        fin >> Ctaf;
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      if (fin.get() == 'Y') {
        Landing_Fee = true;
      }
      if (fin.peek() != ',') {
        fin.get();
      }
    }
    fin >> comma;

    if (fin.peek() != '\r' && fin.peek() != '\n') {
      if (fin.get() == 'Y') {
        Wind_Indic = true;
      }
    }

    Airport airport(OBJECTID, the_geom, Fac_Type, Field_Office, State_Name,
                    County, City, Fac_Name, Fac_Use, Sectional, Fuel_Types,
                    Elevation, Unicom, Ctaf, Atc_Tower, Landing_Fee,
                    Wind_Indic);
    objs.push_back(airport);
    counter += 1;
  }
  fin.close();
  return true;
}

/**
 * This verifies that all fields that should be set are set with
 * good values.
 */
void verifyAllFieldsSet(std::vector<Airport> &objs) {
  int i = 0;
  for (Airport &airport : objs) {
    // Row ID should always = i + 1
    if (airport.getObjectid() != i + 1) {
      std::cout << "Bad value for row ID at record " << i << std::endl;
    }
    std::string FacName = airport.getFacName();
    if (FacName.compare("NONE") == 0) {
      std::cout << "Bad value for Airport name at record " << i << std::endl;
    }
    i += 1;
  }
}

/**
 * Airport object tests.
 * To ensure constructors, getters, and setters all work properly.
 */
bool AirportTest() {
  bool passed = true;
  Airport testObject = Airport();
  // Test setters and getters
  testObject.setObjectid(1);
  if (testObject.getObjectid() != 1) {
    std::cout << "FAILED OBJECTID test" << std::endl;
    passed = false;
  }

  testObject.setTheGeom("Fred");
  if (testObject.getTheGeom() != "Fred") {
    std::cout << "FAILED the-geom, test" << std::endl;
    passed = false;
  }
  testObject.setFacType("PU");
  if (testObject.getFacType() != "PU") {
    std::cout << "FAILED FacType test" << std::endl;
    passed = false;
  }
  testObject.setFieldOffice("LAX");
  if (testObject.getFieldOffice() != "LAX") {
    std::cout << "FAILED FieldOffice test" << std::endl;
    passed = false;
  }
  testObject.setStateName("Vermont");
  if (testObject.getStateName() != "Vermont") {
    std::cout << "FAILED StateName test" << std::endl;
    passed = false;
  }
  testObject.setCounty("Chittenden");
  if (testObject.getCounty() != "Chittenden") {
    std::cout << "FAILED StateName test" << std::endl;
    passed = false;
  }
  testObject.setCity("Burlington");
  if (testObject.getCity() != "Burlington") {
    std::cout << "FAILED City test" << std::endl;
    passed = false;
  }
  testObject.setFacName("JFK");
  if (testObject.getFacName() != "JFK") {
    std::cout << "FAILED AirportName test" << std::endl;
    passed = false;
  }
  testObject.setFacUse("PU");
  if (testObject.getFacUse() != "PU") {
    std::cout << "FAILED FacUse test" << std::endl;
    passed = false;
  }
  testObject.setElevation(0.0);
  if (testObject.getElevation() != 0.0) {
    std::cout << "FAILED elevation test" << std::endl;
    passed = false;
  }
  testObject.setSectional("MONTREAL");
  if (testObject.getSectional() != "MONTREAL") {
    std::cout << "FAILED Sectional test" << std::endl;
    passed = false;
  }
  testObject.setFuelTypes("Jet-A");
  if (testObject.getFuelTypes() != "Jet-A") {
    std::cout << "FAILED FuelTypes test" << std::endl;
    passed = false;
  }
  testObject.setAtcTower(true);
  if (!testObject.isAtcTower()) {
    std::cout << "FAILED AtcTower test" << std::endl;
    passed = false;
  }
  testObject.setUnicom(123.45);
  if (testObject.getUnicom() != 123.45) {
    std::cout << "FAILED Unicom test" << std::endl;
    passed = false;
  }
  testObject.setCtaf(123.45);
  if (testObject.getCtaf() != 123.45) {
    std::cout << "FAILED Ctaf test" << std::endl;
    passed = false;
  }
  testObject.setLandingFee(true);
  if (!testObject.isLandingFee()) {
    std::cout << "FAILED LandingFee test" << std::endl;
    passed = false;
  }
  testObject.setWindIndic(true);
  if (!testObject.isWindIndic()) {
    std::cout << "FAILED WindIndic test" << std::endl;
    passed = false;
  }
  // Test initialization (and getters)

  Airport testObject2 = Airport(1, "Fred", "PU", "LAX", "Vermont", "Chittenden",
                                "Burlington", "JFK", "PU", "MONTREAL", "Jet-A",
                                0.0, 123.45, 678.90, true, true, true);
  if (testObject2.getObjectid() != 1 || testObject2.getTheGeom() != "Fred" ||
      testObject2.getFacType() != "PU" ||
      testObject2.getFieldOffice() != "LAX" ||
      testObject2.getStateName() != "Vermont" ||
      testObject2.getCounty() != "Chittenden" ||
      testObject2.getCity() != "Burlington" ||
      testObject2.getFacName() != "JFK" || testObject2.getFacUse() != "PU" ||
      testObject2.getElevation() != 0.0 ||
      testObject2.getSectional() != "MONTREAL" ||
      testObject2.getFuelTypes() != "Jet-A" || !testObject2.isAtcTower() ||
      testObject2.getUnicom() != 123.45 || testObject2.getCtaf() != 678.90 ||
      !testObject2.isLandingFee() || !testObject2.isWindIndic()) {
    std::cout << "FAILED non-default constructor test" << std::endl;
    passed = false;
  }
  return passed;
}
