#ifndef __PROCALC_FRAGMENTS_F_TETROMINOS_SPEC_HPP__
#define __PROCALC_FRAGMENTS_F_TETROMINOS_SPEC_HPP__


#include <QString>
#include "fragment_spec.hpp"


struct FTetrominosSpec : public FragmentSpec {
  FTetrominosSpec()
    : FragmentSpec("FTetrominos", {}) {}

  QString backgroundImage;
};


#endif
