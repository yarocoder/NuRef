//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
// $Id: DetectorConstruction.hh 66586 2012-12-21 10:48:39Z ihrivnac $
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4GDMLParser.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include<vector>

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class DetectorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
   ~DetectorConstruction();

  public:
  
    virtual G4VPhysicalVolume* Construct();
    G4LogicalVolume* ReturnVolume() const
    {
    return fScoringVolume;
    }
    G4LogicalVolume* GetScoringVolume() const
    {
    return fScoringVolume;
    }

    std::vector<G4LogicalVolume*> GetScoringVolume1() const
    {
    return fScoringVolume1;
    }

    // Reading GDML
    //
    void SetReadFile( const G4String& File );
         
                       
  private:
  
    // G4double           fTargetLength; 
    // G4double           fTargetRadius;
    // G4Material*        fTargetMater;
    // G4LogicalVolume*   fLogicTarget;
                 
    // G4double           fDetectorLength;
    // G4double           fDetectorThickness;
    // G4Material*        fDetectorMater;
    // G4LogicalVolume*   fLogicDetector;

    G4GDMLParser       fParser;          
    G4double           fWorldLength;
    G4double           fWorldRadius;
    G4Material*        fWorldMater;     
    G4VPhysicalVolume* fPhysiWorld;
    G4int fWritingChoice;
    G4String fReadFile;            
    DetectorMessenger* fDetectorMessenger;
    G4LogicalVolume* fScoringVolume;
    std::vector<G4LogicalVolume*> fScoringVolume1;

    
    void DefineMaterials();
    G4VPhysicalVolume* ConstructVolumes();     
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif

