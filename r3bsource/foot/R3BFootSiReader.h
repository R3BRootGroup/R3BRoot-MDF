/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// ----------------------------------------------------------------------
// -----                         R3BFootSiReader                    -----
// -----             Created 19/07/21  by J.L. Rodriguez-Sanchez    -----
// ----------------------------------------------------------------------

#ifndef R3BFootSiReader_H
#define R3BFootSiReader_H

#include "R3BReader.h"
#include <Rtypes.h>

class TClonesArray;

struct EXT_STR_h101_FOOT_t;
typedef struct EXT_STR_h101_FOOT_t EXT_STR_h101_FOOT;
typedef struct EXT_STR_h101_FOOT_onion_t EXT_STR_h101_FOOT_onion;
class ext_data_struct_info;

class R3BFootSiReader : public R3BReader
{
  public:
    // Standard constructor
    R3BFootSiReader(EXT_STR_h101_FOOT_onion*, size_t);

    // Destructor
    virtual ~R3BFootSiReader();

    // Setup structure information
    virtual Bool_t Init(ext_data_struct_info*) override;

    // Read data from full event structure
    virtual Bool_t Read() override;

    // Reset
    virtual void Reset() override;

    // Accessor to select online mode
    void SetOnline(Bool_t option) { fOnline = option; }

  private:
    // An event counter
    unsigned int fNEvent;
    // Reader specific data structure from ucesb
    EXT_STR_h101_FOOT_onion* fData;
    // Data offset
    size_t fOffset;
    // Don't store data for online
    Bool_t fOnline;
    // Number of silicon detectors
    Int_t fNbDet;
    // Output array
    TClonesArray* fArray;

  public:
    ClassDefOverride(R3BFootSiReader, 0);
};

#endif /* R3BFootSiReader_H */
