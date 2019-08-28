// -----------------------------------------------------------------------------
//  G4Basic | DetectorConstruction.h
//
//  Class for the definition of the detector geometry and materials.
//   * Author: Justo Martin-Albo, Taylor Contreras
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#ifndef DETECTOR_CONSTRUCTION_H
#define DETECTOR_CONSTRUCTION_H

#include <G4VUserDetectorConstruction.hh>
#include <G4MaterialPropertiesTable.hh>

class G4Material;


class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  virtual ~DetectorConstruction();
  virtual G4VPhysicalVolume* Construct();

  G4LogicalVolume* GetEnergyPlane() const { return fEnergyPlane; }
  G4LogicalVolume* GetTrackingPlane() const { return fTrackingPlane; }
  //G4double Scintillation(G4double energy);

private:
  G4Material* DefineNeon() const;
  G4Material* DefineXenon() const;
  G4MaterialPropertiesTable* PTFE();
  G4double Scintillation(G4double energy) const;
  G4double RefractiveIndex(G4double energy) const;
  G4LogicalVolume* fEnergyPlane;
  G4LogicalVolume* fTrackingPlane;
  G4double fpressure;
};

#endif
