// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>
#include <bitset>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using PhotoMagic::FibLFSR;

BOOST_AUTO_TEST_CASE(testStepInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testExceptionConstructor) {
  BOOST_CHECK_THROW(FibLFSR("1011011020110110"), std::invalid_argument);
  BOOST_CHECK_THROW(FibLFSR("10110110a0110110"), std::invalid_argument);
  BOOST_CHECK_NO_THROW(FibLFSR("1011011000110110"));
}

BOOST_AUTO_TEST_CASE(testExceptionGenerate) {
  FibLFSR l("1011011000110110");
  BOOST_CHECK_THROW(l.generate(-1), std::invalid_argument);
  BOOST_CHECK_THROW(l.generate(-2), std::invalid_argument);
  BOOST_CHECK_NO_THROW(l.generate(0));
  BOOST_CHECK_NO_THROW(l.generate(1));
  BOOST_CHECK_NO_THROW(l.generate(2));
}

BOOST_AUTO_TEST_CASE(testConstructor) {
  std::string str("1011011000110110");
  FibLFSR l(str);
  std::ostringstream output;
  output << l;
  BOOST_REQUIRE_EQUAL(output.str(), str);
}

BOOST_AUTO_TEST_CASE(testStep) {
  FibLFSR l("1011011000110110");
  int tempBit;
  int correctBits[] = { 0, 0, 0, 1, 1, 0, 0, 1, 1, 0 };
  std::string correctStrings[] = {
    "0110110001101100",
    "1101100011011000",
    "1011000110110000",
    "0110001101100001",
    "1100011011000011",
    "1000110110000110",
    "0001101100001100",
    "0011011000011001",
    "0110110000110011",
    "1101100001100110"
  };
  for (int i = 0; i < 10; i++) {
    tempBit = l.step();
    std::ostringstream output;
    output << l;
    BOOST_REQUIRE_EQUAL(tempBit, correctBits[i]);
    BOOST_REQUIRE_EQUAL(output.str(), correctStrings[i]);
  }
}
BOOST_AUTO_TEST_CASE(testGenerate) {
  FibLFSR l("1011011000110110");
  int tempSteps;
  int correctSteps[] = { 3, 6, 14, 24, 1, 13, 28 };
  std::string correctStrings[] = {
    "1100011011000011",
    "1101100001100110",
    "0000110011001110",
    "1001100111011000",
    "0011101100000001",
    "0110000000101101",
    "0000010110111100"
  };
  for (int i = 0; i < 7; i++) {
    tempSteps = l.generate(5);
    std::ostringstream output;
    output << l;
    BOOST_REQUIRE_EQUAL(tempSteps, correctSteps[i]);
    BOOST_REQUIRE_EQUAL(output.str(), correctStrings[i]);
  }
}

BOOST_AUTO_TEST_CASE(testIntConstructor) {
  unsigned int number = 1725;
  FibLFSR l(number);
  std::ostringstream output1;
  output1 << l;
  std::ostringstream output2;
  output2 << std::bitset<16>(number);
  BOOST_REQUIRE_EQUAL(output1.str(), output2.str());
}

BOOST_AUTO_TEST_CASE(testAlphaPassword) {
  std::string password = "A1";
  FibLFSR l = FibLFSR::fromPassword(password);
  std::ostringstream output;
  output << l;
  BOOST_REQUIRE_EQUAL(output.str(), "0100000100110001");
}
