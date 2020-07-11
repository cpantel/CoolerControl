#include <CppUTest/TestHarness.h>
#include "../../src/brain/Brain.hpp"
TEST_GROUP(brain) {
  void setup() {
  }

  void teardown() {

  }
};

TEST_GROUP(powerOff) {
  void setup() {
  }

  void teardown() {

  }
};

TEST_GROUP(simulation) {
  void setup() {
  }

  void teardown() {

  }
};

TEST_GROUP(newTest) {
  void setup() {
  }

  void teardown() {

  }
};

TEST(brain,setFirstMeasure) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   CHECK_EQUAL(17,brain.getAverage());
}

// bad test, enhance it
TEST(brain,respectWeights) {
   Brain brain(50,50,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   CHECK_EQUAL(17,brain.getAverage());
}


TEST(brain,setSomeMeasures) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(18,18);
   brain.addMeasure(19,19);
   CHECK_EQUAL(18,brain.getAverage());
}

TEST(brain, getTendencyNoAmpNoChange) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   CHECK_EQUAL(0,brain.getTendency());
}

TEST(brain, getTendencyDoubleAmpNoChange) {
   Brain brain(1,1,2,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   CHECK_EQUAL(0,brain.getTendency());
}

TEST(brain, getTendencyNoAmpUpChange1) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(18,18);
   CHECK_EQUAL(1,brain.getTendency());
}

TEST(brain, getTendencyNoAmpUpChangeSaturated) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(21,21);
   CHECK_EQUAL(2,brain.getTendency());
}

TEST(brain, getTendencyDoubleAmpUpChange) {
   Brain brain(1,1,2,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(18,18);
   CHECK_EQUAL(2,brain.getTendency());
}

TEST(brain, getTendencyNoAmpDoubleUpChange) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(19,19);
   CHECK_EQUAL(2,brain.getTendency());
}

TEST(brain, getTendencyNoAmpDownChange) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(15,15);
   CHECK_EQUAL(-1,brain.getTendency());
}

TEST(brain, getTendencyNoAmpDownChangeSaturated) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(14,14);
   CHECK_EQUAL(-1,brain.getTendency());
}

TEST(brain, getTendency3AmpDownChangeSaturated) {
   Brain brain(1,1,3,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(14,14);
   CHECK_EQUAL(-1,brain.getTendency());
}

// delta Ts == Tr

TEST(brain,getDeltaSpeed_delta_plano_bajo) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(18,17);
   brain.addMeasure(17,17);
   CHECK_EQUAL(0,brain.getDeltaSpeed());
}


TEST(brain,getDeltaSpeed_delta_plano_nada) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   CHECK_EQUAL(0,brain.getDeltaSpeed());
}

TEST(brain,getDeltaSpeed_delta_plano_apenas_subio) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(18,18);
   CHECK_EQUAL(0,brain.getDeltaSpeed());
}

TEST(brain,getDeltaSpeed_delta_plano_subio) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(16,16);
   brain.addMeasure(17,17);
   CHECK_EQUAL(10,brain.getDeltaSpeed());
}

TEST(brain,getDeltaSpeed_delta_plano_subio_mucho) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(15,15);
   brain.addMeasure(17,17);
   CHECK_EQUAL(20,brain.getDeltaSpeed());
}


// delta Ts < Tr

TEST(brain,getDeltaSpeed_delta_negativo_bajo) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(15,15);
   brain.addMeasure(13,13);
   CHECK_EQUAL(-20,brain.getDeltaSpeed());
}

TEST(brain,getDeltaSpeed_delta_negativo_nada) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(16,16);
   CHECK_EQUAL(0,brain.getDeltaSpeed());
}


TEST(brain,getDeltaSpeed_delta_negativo_subio) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(14,14);
   brain.addMeasure(15,15);
   CHECK_EQUAL(10,brain.getDeltaSpeed());
}

TEST(brain,getDeltaSpeed_delta_negativo_subio_mucho) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(14,14);
   brain.addMeasure(16,16);
   CHECK_EQUAL(20,brain.getDeltaSpeed());
}

// delta Ts > Tr

TEST(brain,getDeltaSpeed_delta_positivo_bajo) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(21,21);
   brain.addMeasure(19,19);
   CHECK_EQUAL(0,brain.getDeltaSpeed());
}


TEST(brain,getDeltaSpeed_delta_positivo_nada) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(19,19);
   CHECK_EQUAL(10,brain.getDeltaSpeed());
}


TEST(brain,getDeltaSpeed_delta_positivo_subio) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(18,18);
   brain.addMeasure(19,19);
   CHECK_EQUAL(20,brain.getDeltaSpeed());
}


TEST(brain,getDeltaSpeed_delta_positivo_subio_mucho) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(18,18);
   brain.addMeasure(20,20);
   CHECK_EQUAL(50,brain.getDeltaSpeed());
}

/*

 Tendencia       | Ts < Tr | Ts == Tr | Ts > Tr |
(+2) Subió mucho |    +    |    ++    |   +++   |          50
(+1) Subió       |    =    |     +    |    ++   |          20
 (0) Igual       |    -    |     =    |     +   | -10      10
(-1) Bajó        |   --    |     -    |     =   | -20


 Tendencia       | Ts < Tr | Ts == Tr | Ts > Tr |
(+2) Subió mucho |    10   |    20    |    50   |          50
(+1) Subió       |     0   |    10    |    20   |          20
 (0) Igual       |   -10   |     0    |    10   | -10      10
(-1) Bajó        |   -20   |   -10    |     0   | -20


*/



TEST(brain,newSpeed_nada) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   brain.addMeasure(17,17);
   CHECK_EQUAL(80,brain.getNewSpeed(80));
}

TEST(brain,newSpeed_respeta_minimo) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(17,17);
   CHECK_EQUAL(brain.getMinSpeed(),brain.getNewSpeed(brain.getMinSpeed() - 10 ));
}

TEST(brain,newSpeed_respeta_maximo) {
   Brain brain(1,1,1,17,17,64,2,20,10,0,10,20,50);
   brain.addMeasure(20,20);
   CHECK_EQUAL(255,brain.getNewSpeed(255 ));
}


TEST(newTest, turn_off_cooler) {
   Brain brain(1,1,1,40,40,64,2,20,10,1,10,20,50);
   brain.addMeasure(30,30);
   CHECK_EQUAL(brain.getMinSpeed(),brain.getNewSpeed(brain.getMinSpeed() + 5 ));
}

TEST(simulation, simulacion_newSpeed_cero_es_cero) {
   Brain brain(1,1,1,40,40,64,2,20,10,0,10,20,50);
   brain.addMeasure(20,20);
   CHECK_EQUAL(117,brain.getNewSpeed(127 ));
   brain.addMeasure(30,30);
   CHECK_EQUAL(127,brain.getNewSpeed(117 ));
   brain.addMeasure(35,35);
   CHECK_EQUAL(137,brain.getNewSpeed(127 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(157,brain.getNewSpeed(137 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(157,brain.getNewSpeed(157 ));
   brain.addMeasure(45,45);
   CHECK_EQUAL(207,brain.getNewSpeed(157 ));
   brain.addMeasure(45,45);
   CHECK_EQUAL(217,brain.getNewSpeed(207 ));
   brain.addMeasure(45,45);
   CHECK_EQUAL(227,brain.getNewSpeed(217 ));
   brain.addMeasure(44,44);
   CHECK_EQUAL(237,brain.getNewSpeed(227 ));
   brain.addMeasure(43,43);
   CHECK_EQUAL(237,brain.getNewSpeed(227 ));
   brain.addMeasure(42,42);
   CHECK_EQUAL(247,brain.getNewSpeed(237 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(247,brain.getNewSpeed(247 ));
}


TEST(simulation, simulacion_newSpeed_cero_es_menos_uno) {
   Brain brain(1,1,1,40,40,64,2,20,10,1,10,20,50);
   brain.addMeasure(20,20);
   CHECK_EQUAL(117,brain.getNewSpeed(127 ));
   brain.addMeasure(30,30);
   CHECK_EQUAL(127,brain.getNewSpeed(117 ));
   brain.addMeasure(35,35);
   CHECK_EQUAL(137,brain.getNewSpeed(127 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(157,brain.getNewSpeed(137 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(156,brain.getNewSpeed(157 ));
   brain.addMeasure(45,45);
   CHECK_EQUAL(206,brain.getNewSpeed(156 ));
   brain.addMeasure(45,45);
   CHECK_EQUAL(216,brain.getNewSpeed(206 ));
   brain.addMeasure(45,45);
   CHECK_EQUAL(226,brain.getNewSpeed(216 ));
   brain.addMeasure(44,44);
   CHECK_EQUAL(236,brain.getNewSpeed(226 ));
   brain.addMeasure(43,43);
   CHECK_EQUAL(236,brain.getNewSpeed(226 ));
   brain.addMeasure(42,42);
   CHECK_EQUAL(246,brain.getNewSpeed(236 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(245,brain.getNewSpeed(246 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(244,brain.getNewSpeed(245 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(243,brain.getNewSpeed(244 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(242,brain.getNewSpeed(243 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(241,brain.getNewSpeed(242 ));
   brain.addMeasure(41,41);
   CHECK_EQUAL(240,brain.getNewSpeed(241 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(239,brain.getNewSpeed(240 ));
   brain.addMeasure(40,40);
   CHECK_EQUAL(238,brain.getNewSpeed(239 ));
}

TEST(powerOff, turn_off_cooler) {
   Brain brain(1,1,1,40,40,64,2,20,10,1,10,20,50);
   brain.addMeasure(20,20);
   byte minSpeed = brain.getMinSpeed();
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(minSpeed,brain.getNewSpeed(minSpeed));
   CHECK_EQUAL(0,brain.getNewSpeed(minSpeed));
}

TEST(powerOff, keep_cooler_off) {
   Brain brain(1,1,1,40,40,64,2,20,10,1,10,20,50);
   brain.addMeasure(20,20);
   CHECK_EQUAL(0,brain.getNewSpeed( 0 ));
   brain.addMeasure(20,20);
   CHECK_EQUAL(0,brain.getNewSpeed( 0 ));
}

TEST(powerOff, turn_on_cooler_if_needed) {
   Brain brain(1,1,1,40,40,64,2,20,10,1,10,20,50);
   brain.addMeasure(50,50);
   brain.addMeasure(60,60);
   CHECK_EQUAL(127,brain.getNewSpeed( 0 ));
   brain.addMeasure(40,40);
   brain.addMeasure(40,40);
   brain.addMeasure(30,30);
   CHECK_EQUAL(107,brain.getNewSpeed(127) );
}

