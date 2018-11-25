#ifndef GUI_H
#define GUI_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpinBox>
#include <QSlider>
#include <QCheckBox>
#include <QString>
#include <QMessageBox>
#include <QComboBox>
#include <QStringList>
#include <QList>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class GUI : public QDialog
{
    Q_OBJECT

public:
    GUI();

// Custom slots
public slots:

    // Slot called when widget "browseWorkspace" is pressed - open a file browser to select a workspace
    void selectWorkspaceDialog();

    // Slot called when widget "browseOutputDirectories" is pressed - open a file browser to select a output directories location
    void selectOutputDirectoriesDialog();

    // Slot called when widget "browseDeconvolvedFolder" is pressed - open a file browser to select a deconvolved folder
    void selectDeconvolvedFolderDialog();

    // Slot called when widget "browseReferenceImageMembrane" is pressed - open a file browser to select a reference image for the membrane
    void selectReferenceImageMembraneDialog();

    // Slot called when widget "browseReferenceImageScaffold" is pressed - open a file browser to select a reference image for the scaffold
    void selectReferenceImageScaffoldDialog();

    // Slot called when "Ok" is pressed - Transfer information into text file
    void sendInfoToFile();

    // Slot called when "Cancel" is pressed - Close the GUI
    void quitWhenCancel();

private:
    // Attributes related to text file used to save the parameters input in the GUI window
    string pathToDevFolder = "//192.168.96.33/data5/Valentin/AVIZO_SEGMENTATION_USABLE_SCRIPTS";
    string inputParametersFile = "inputParameters.txt";
    string inputParametersFilePath;

    // "Ok" and "Cancel" buttons widgets
    QPushButton *okButton;
    QPushButton *cancelButton;

    // Layout to contain "Ok" and "Cancel" buttons
    QHBoxLayout *okCancelLayout;

    // Main layout of the QDialog window, to contain the three main widgets "paths", "options" and "advanced"
    QVBoxLayout *mainLayout;

    // The three main widgets
    QGroupBox *paths;
    QGroupBox *options;
    QGroupBox *advanced;

    // ////// Attributes to be contained into the widget "paths"
    // // Main layout of the widget "paths"
    QVBoxLayout *pathsContent;
    // // Layouts to be contained into "pathsContent"
    QGridLayout *workspaceLayout;
    QGridLayout *deconvolvedFolderPathLayout;
    QGridLayout *outputDirectoriesLayout;
    QGridLayout *outputDirectoryLayout;
    QGridLayout *voxelSizeSelectionLayout;
    QGridLayout *channelLayout;
    // // Widgets to be contained into the layouts
    // Widgets to be contained in "workspaceLayout"
    QLabel *labelWorkspace;
    QLineEdit *workspacePath;
    QPushButton *browseWorkspace;
    QString workspace;
    // Widgets to be contained in "deconvolvedFolderPathLayout"
    QLabel *labelDeconvolvedFolder;
    QLineEdit *deconvolvedFolderPath;
    QPushButton *browseDeconvolvedFolder;
    QString deconvolvedFolder;
    // Widgets to be contained in "outputDirectoriesLayout"
    QLabel *labelOutputDirectories;
    QLineEdit *outputDirectoriesPath;
    QPushButton *browseOutputDirectories;
    QString outputDirectories;
    // Widgets to be contained in "outputDirectoryLayout"
    QLabel *labelOutputDirectory;
    QLineEdit *outputDirectoryLine;
    // Widgets to be contained in "voxelSizeSelectionLayout"
    QLabel *labelVoxelSizeSelection;
    QLabel *labelVoxelSizeX;
    QLineEdit *voxelSizeXLine;
    QLabel *labelVoxelSizeY;
    QLineEdit *voxelSizeYLine;
    QLabel *labelVoxelSizeZ;
    QLineEdit *voxelSizeZLine;
    // Widgets to be contained in "channelLayout"
    QLabel *labelChannel;
    QCheckBox *membraneCheckBox;
    QComboBox *membraneChannel;
    QCheckBox *paxilinCheckBox;
    QComboBox *paxilinChannel;
    QCheckBox *nucleusCheckBox;
    QComboBox *nucleusChannel;
    QCheckBox *scaffoldCheckBox;
    QComboBox *scaffoldChannel;

    // ////// Attributes to be contained into the widget "options"
    // // Main layout of the widget "options"
    QVBoxLayout *optionsContent;
    // // Layouts to be contained into "optionsContent"
    QGridLayout *imageNameLayout;
    QGridLayout *membraneThresholdLayout;
    QGridLayout *closingValueLayout;
    QGridLayout *flagLayout;
    // // Widgets to be contained into the layouts
    // Widgets to be contained in "imageNameLayout"
    QLabel *labelImageName;
    QLineEdit *imageNameLine;
    // Widgets to be contained in "membraneThresholdLayout"
    QLabel *labelMembraneThreshold;
    QSpinBox *membraneThresholdSpinBox;
    QSlider *membraneThresholdSlider;
    // Widgets to be contained in "closingValueLayout"
    QLabel *labelClosingValue;
    QSpinBox *closingValueSpinBox;
    QSlider *closingValueSlider;
    // Widgets to be contained in "flagLayout"
    QCheckBox *isUseNucleusForMembrane;
    QCheckBox *isEllipsoidFit;

    // ////// Attributes to be contained into the widget "advanced"
    // // Main layout of the widget "advanced"
    QVBoxLayout *advancedContent;
    // Layouts to be contained into "advancedContent"
    QGridLayout *referenceImageMembranePathLayout;
    QGridLayout *referenceImageScaffoldPathLayout;
    // // Widgets to be contained into the layouts
    // Widgets to be contained in "referenceImageMembranePathLayout"
    QLabel *labelReferenceImageMembrane;
    QLineEdit *referenceImageMembranePath;
    QPushButton *browseReferenceImageMembrane;
    QString referenceImageMembrane;
    // Widgets to be contained in "referenceImageScaffoldPathLayout"
    QLabel *labelReferenceImageScaffold;
    QLineEdit *referenceImageScaffoldPath;
    QPushButton *browseReferenceImageScaffold;
    QString referenceImageScaffold;

};

#endif // GUI_H
