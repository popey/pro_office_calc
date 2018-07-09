#ifndef __PROCALC_STATES_ST_BACK_TO_NORMAL_HPP__
#define __PROCALC_STATES_ST_BACK_TO_NORMAL_HPP__


#include "fragments/f_main/f_main_spec.hpp"


namespace st_back_to_normal {


FMainSpec* makeFMainSpec(const AppConfig& appConfig) {
  FMainSpec* mainSpec = new FMainSpec;
  mainSpec->calculatorSpec.setEnabled(true);
  mainSpec->aboutDialogText = "";
  mainSpec->aboutDialogText += QString("<p align='center'><big>Pro Office Calculator</big>") +
    "<br>Version 1.0.0</p>"
    "<p align='center'>Copyright (c) 2017 Rob Jinman. All rights reserved.</p>"
    "<i>With help from" + appConfig.playerName.c_str() + "</i>";

  return mainSpec;
}


}


#endif
