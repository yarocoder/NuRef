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
/// \file HistoManager.cc
/// \brief Implementation of the HistoManager class
//
// $Id: HistoManager.cc 98265 2016-07-04 17:47:54Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "HistoManager.hh"
#include "DetectorConstruction.hh"
#include "G4UnitsTable.hh"
#include "Run.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::HistoManager(DetectorConstruction* det)
  : fFileName("HFNG"), fDetector(det), fScoringVolume1(0.)
{
  Book();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::~HistoManager()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void HistoManager::Book()
{
  // Obtain the run manager.
  Run* run = static_cast<Run*>(
        G4RunManager::GetRunManager()->GetNonConstCurrentRun()); 

  // Create or get analysis manager
  // The choice of analysis technology is done via selection of a namespace
  // in HistoManager.hh
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetFileName(fFileName);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetActivation(true);     // Enable activation of histograms
  
  //get scoring volume
  //
  const DetectorConstruction* detectorConstruction = static_cast<const DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

  // G4LogicalVolume* fScoringVolume1 = detectorConstruction->GetScoringVolume();

 // if (fScoringVolume1.empty()){fScoringVolume1 = detectorConstruction->GetScoringVolume1();}
//if (fScoringVolume1.empty()){fScoringVolume1 = fDetector->GetScoringVolume1();}
//G4cout<<"First scoring volume is: "<<fScoringVolume1[0]<<G4endl;
//fScoringVolume1 = fDetector->GetScoringVolume1();
//G4cout<<"Scoring volume size is: "<<fScoringVolume1.size()<<G4endl;
//getchar();
  
  // fScoringVolume1 = detectorConstruction->GetScoringVolume1();

  //for(int j = 0; j < 3; j++)
   // {
      // Retrieve the name of the current scoring volume.
  //  if (!fScoringVolume) { 
   //  fScoringVolume = detectorConstruction->ReturnVolume();   
  // }
   //   G4String volume_name = fScoringVolume1[j]->GetName();

      // Define histograms start values.
      const G4int kMaxHisto = 9;
      const G4String id[] = {"0", "1", "2","3", "4", "5", "6", "7", "8"};
      //const G4String id[] = {std::to_string(j*10), std::to_string(j*10 + 1), std::to_string(j*10 + 2)};
      const G4String title[] = 
                    {
                      "All Neutrons Entering Volume 1",               // ID = 0
                      "All Neutrons Entering Volume 2",               // ID = 1
                      "Energy of Neutrons Scattered Into Volume 1",   // ID = 2
                      "Energy of Neutrons Scattered Into Volume 2",   // ID = 3
                      "Neutron Captured in Volume 1",                 // ID = 4
                      "Neutron Captured in Volume 2",                 // ID = 5
                      "Neutron Flux Into Volume 1",                   // ID = 6
                      "Neutron Flux Into Volume 2",                   // ID = 7
                      "Neutrons Leaving World"                        // ID = 8
                    };

      // Bin parameters               
      G4int nbins = 500;
      G4double x_min = 0.;  // Minimum value on the x-axis
      G4double x_max = 5.;  // Minimum value on the y-axis

      // Create all histograms
      for (G4int k=0; k<kMaxHisto; k++)
        {
          G4int ih = analysisManager->CreateH1(id[k], title[k], nbins, x_min, x_max);
          analysisManager->SetH1Activation(ih, true);
        }
    //}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
