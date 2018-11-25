#include "gui.h"

GUI::GUI() : QDialog()
{
    inputParametersFilePath = pathToDevFolder+"/DevFolder/"+inputParametersFile;
    this->setWindowTitle("Parameters Setup");

    // Creations of the main layout, and the three main widgets "paths", "options" and "advanced"
    mainLayout = new QVBoxLayout;
    paths = new QGroupBox("");
    options = new QGroupBox("Options");
    advanced = new QGroupBox("Advanced");


    // ////// "Ok" and "Cancel" buttons management - Start

    // "Ok" and "Cancel" buttons widgets
    okButton = new QPushButton;
    okButton->setText("Ok");
    okButton->setAutoDefault(true);
    cancelButton = new QPushButton;
    cancelButton->setText("Cancel");

    // Assembly of the layout containing "Ok" and "Cancel"
    okCancelLayout = new QHBoxLayout;
    okCancelLayout->addWidget(okButton);
    okCancelLayout->addWidget(cancelButton);

    // When "Ok" is pushed, call "sendInfoToFile()" - In this example, this line is disabled, nothing happens when "Ok" is pressed
    //QObject::connect(okButton,SIGNAL(clicked(bool)),this,SLOT(sendInfoToFile()));

    // When "Cancel" is pushed, call "quitWhenCancel()" - In this example, this line is disabled, nothing happens when "Cancel" is pressed
    //QObject::connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(quitWhenCancel()));

    // ////// "Ok" and "Cancel" buttons management - End


    // ////// Management of the widget "paths" - Start

    // Create the layouts to be contained in "paths"
    pathsContent = new QVBoxLayout;
    workspaceLayout = new QGridLayout;
    deconvolvedFolderPathLayout = new QGridLayout;
    outputDirectoriesLayout = new QGridLayout;
    outputDirectoryLayout = new QGridLayout;
    voxelSizeSelectionLayout = new QGridLayout;
    channelLayout = new QGridLayout;

    // Create widgets to be contained in "workspaceLayout"
    labelWorkspace = new QLabel;
    labelWorkspace->setText("Choose workspace");
    workspacePath = new QLineEdit;
    workspacePath->setText("D:/Valentin/stacks");
    browseWorkspace = new QPushButton;
    browseWorkspace->setText("browse");
    QObject::connect(browseWorkspace,SIGNAL(clicked(bool)),this,SLOT(selectWorkspaceDialog()));

    // Create widgets to be contained in "deconvolvedFolderPathLayout"
    labelDeconvolvedFolder = new QLabel;
    labelDeconvolvedFolder->setText("Choose the name of your deconvolved folder");
    deconvolvedFolderPath = new QLineEdit;
    deconvolvedFolderPath->setText("deconvolved");
    browseDeconvolvedFolder = new QPushButton;
    browseDeconvolvedFolder->setText("browse");
    QObject::connect(browseDeconvolvedFolder,SIGNAL(clicked(bool)),this,SLOT(selectDeconvolvedFolderDialog()));

    // Create widgets to be contained in "outputDirectoriesLayout"
    labelOutputDirectories = new QLabel;
    labelOutputDirectories->setText("Choose output directories location");
    outputDirectoriesPath = new QLineEdit;
    outputDirectoriesPath->setText("D:/Valentin/outputs");
    browseOutputDirectories = new QPushButton;
    browseOutputDirectories->setText("browse");
    QObject::connect(browseOutputDirectories,SIGNAL(clicked(bool)),this,SLOT(selectOutputDirectoriesDialog()));

    // Create widgets to be contained in "outputDirectoryLayout"
    labelOutputDirectory = new QLabel;
    labelOutputDirectory->setText("Write the name of the output directory you want to create");
    outputDirectoryLine = new QLineEdit;
    outputDirectoryLine->setText("avizoOutputGUI2");

    // Create widgets to be contained in "voxelSizeSelectionLayout"
    labelVoxelSizeSelection = new QLabel;
    labelVoxelSizeSelection->setText("Setup the voxel size :");
    labelVoxelSizeX = new QLabel;
    labelVoxelSizeX->setText("voxel size X :");
    voxelSizeXLine = new QLineEdit;
    voxelSizeXLine->setText("0.104");
    voxelSizeXLine->setValidator( new QDoubleValidator(0, 1000, 10, this) );
    labelVoxelSizeY = new QLabel;
    labelVoxelSizeY->setText("voxel size Y :");
    voxelSizeYLine = new QLineEdit;
    voxelSizeYLine->setText("0.104");
    voxelSizeYLine->setValidator( new QDoubleValidator(0, 1000, 10, this) );
    labelVoxelSizeZ = new QLabel;
    labelVoxelSizeZ->setText("voxel size Z :");
    voxelSizeZLine = new QLineEdit;
    voxelSizeZLine->setText("0.1");
    voxelSizeZLine->setValidator( new QDoubleValidator(0, 1000, 10, this) );

    // Create widgets to be contained in "channelLayout"
    labelChannel = new QLabel;
    labelChannel->setText("Select the channels you want to segment");
    membraneCheckBox = new QCheckBox;
    membraneCheckBox->setText("Membrane");
    membraneCheckBox->setChecked(true);
    membraneChannel = new QComboBox;
    membraneChannel->addItems(QStringList {"561","488","405","642"});
    membraneChannel->setCurrentIndex(0);
    paxilinCheckBox = new QCheckBox;
    paxilinCheckBox->setText("Paxilin");
    paxilinCheckBox->setChecked(true);
    paxilinChannel = new QComboBox;
    paxilinChannel->addItems(QStringList {"561","488","405","642"});
    paxilinChannel->setCurrentIndex(1);
    nucleusCheckBox = new QCheckBox;
    nucleusCheckBox->setText("Nucleus");
    nucleusCheckBox->setChecked(true);
    nucleusChannel = new QComboBox;
    nucleusChannel->addItems(QStringList {"561","488","405","642"});
    nucleusChannel->setCurrentIndex(2);
    scaffoldCheckBox = new QCheckBox;
    scaffoldCheckBox->setText("Scaffold");
    scaffoldCheckBox->setChecked(true);
    scaffoldChannel = new QComboBox;
    scaffoldChannel->addItems(QStringList {"561","488","405","642"});
    scaffoldChannel->setCurrentIndex(3);

    // Add widgets into "workspaceLayout"
    workspaceLayout->addWidget(labelWorkspace,0,0);
    workspaceLayout->addWidget(workspacePath,1,0);
    workspaceLayout->addWidget(browseWorkspace,1,1);

    // Add widgets into "deconvolvedFolderPathLayout"
    deconvolvedFolderPathLayout->addWidget(labelDeconvolvedFolder,0,0);
    deconvolvedFolderPathLayout->addWidget(deconvolvedFolderPath,1,0);
    deconvolvedFolderPathLayout->addWidget(browseDeconvolvedFolder,1,1);

    // Add widgets into "outputDirectoriesLayout"
    outputDirectoriesLayout->addWidget(labelOutputDirectories,0,0);
    outputDirectoriesLayout->addWidget(outputDirectoriesPath,1,0);
    outputDirectoriesLayout->addWidget(browseOutputDirectories,1,1);
    outputDirectoryLayout->addWidget(labelOutputDirectory);
    outputDirectoryLayout->addWidget(outputDirectoryLine);

    // Add widgets into "voxelSizeSelectionLayout"
    voxelSizeSelectionLayout->addWidget(labelVoxelSizeSelection,0,0);
    voxelSizeSelectionLayout->addWidget(labelVoxelSizeX,1,0);
    voxelSizeSelectionLayout->addWidget(voxelSizeXLine,1,1);
    voxelSizeSelectionLayout->addWidget(labelVoxelSizeY,2,0);
    voxelSizeSelectionLayout->addWidget(voxelSizeYLine,2,1);
    voxelSizeSelectionLayout->addWidget(labelVoxelSizeZ,3,0);
    voxelSizeSelectionLayout->addWidget(voxelSizeZLine,3,1);

    // Add widgets into "channelLayout"
    channelLayout->addWidget(labelChannel,0,0);
    channelLayout->addWidget(membraneCheckBox,1,0);
    channelLayout->addWidget(membraneChannel,1,1);
    channelLayout->addWidget(paxilinCheckBox,2,0);
    channelLayout->addWidget(paxilinChannel,2,1);
    channelLayout->addWidget(nucleusCheckBox,3,0);
    channelLayout->addWidget(nucleusChannel,3,1);
    channelLayout->addWidget(scaffoldCheckBox,4,0);
    channelLayout->addWidget(scaffoldChannel,4,1);

    // Add layouts into "pathsContent" layout
    pathsContent->addLayout(workspaceLayout);
    pathsContent->addLayout(deconvolvedFolderPathLayout);
    pathsContent->addLayout(outputDirectoriesLayout);
    pathsContent->addLayout(outputDirectoryLayout);
    pathsContent->addLayout(voxelSizeSelectionLayout);
    pathsContent->addLayout(channelLayout);

    //
    paths->setLayout(pathsContent);

    // ////// Management of the layout "paths" - End


    // ////// Management of the widget "options" - Start

    // Create the layouts to be contained in "options"
    optionsContent = new QVBoxLayout;
    imageNameLayout = new QGridLayout;
    membraneThresholdLayout = new QGridLayout;
    closingValueLayout = new QGridLayout;
    flagLayout = new QGridLayout;

    // Create widgets to be contained in "imageNameLayout"
    labelImageName = new QLabel;
    labelImageName->setText("If you want to segment a single image in your workspace : Write the name of the image to segment");
    imageNameLine = new QLineEdit;

    // Create widgets to be contained in "membraneThresholdLayout"
    labelMembraneThreshold = new QLabel;
    labelMembraneThreshold->setText("Choose the membrane thresholds");
    membraneThresholdSpinBox = new QSpinBox;
    membraneThresholdSpinBox->setMinimum(0);
    membraneThresholdSpinBox->setMaximum(255);
    membraneThresholdSpinBox->setValue(6);
    membraneThresholdSlider = new QSlider(Qt::Horizontal);
    membraneThresholdSlider->setMinimum(0);
    membraneThresholdSlider->setMaximum(255);
    membraneThresholdSlider->setValue(6);
    QObject::connect(membraneThresholdSlider,SIGNAL(valueChanged(int)),membraneThresholdSpinBox,SLOT(setValue(int)));
    QObject::connect(membraneThresholdSpinBox,SIGNAL(valueChanged(int)),membraneThresholdSlider,SLOT(setValue(int)));

    // Create widgets to be contained in "closingValueLayout"
    labelClosingValue = new QLabel;
    labelClosingValue->setText("Choose the structuring element size for closing");
    closingValueSpinBox = new QSpinBox;
    closingValueSpinBox->setMinimum(0);
    closingValueSpinBox->setMaximum(10);
    closingValueSpinBox->setValue(1);
    closingValueSlider = new QSlider(Qt::Horizontal);
    closingValueSlider->setMinimum(0);
    closingValueSlider->setMaximum(10);
    closingValueSlider->setValue(1);
    QObject::connect(closingValueSlider,SIGNAL(valueChanged(int)),closingValueSpinBox,SLOT(setValue(int)));
    QObject::connect(closingValueSpinBox,SIGNAL(valueChanged(int)),closingValueSlider,SLOT(setValue(int)));

    // Create widgets to be contained in "flagLayout"
    isUseNucleusForMembrane = new QCheckBox;
    isUseNucleusForMembrane->setText("Use nucleus for membrane segmentation");
    isUseNucleusForMembrane->setChecked(true);
    isEllipsoidFit = new QCheckBox;
    isEllipsoidFit->setText("Ellipsoid fit");
    isEllipsoidFit->setChecked(true);

    // Add widgets into "imageNameLayout"
    imageNameLayout->addWidget(labelImageName);
    imageNameLayout->addWidget(imageNameLine);

    // Add widgets into "membraneThresholdLayout"
    membraneThresholdLayout->addWidget(labelMembraneThreshold,0,0);
    membraneThresholdLayout->addWidget(membraneThresholdSlider,1,0);
    membraneThresholdLayout->addWidget(membraneThresholdSpinBox,1,1);

    // Add widgets into "closingValueLayout"
    closingValueLayout->addWidget(labelClosingValue,0,0);
    closingValueLayout->addWidget(closingValueSlider,1,0);
    closingValueLayout->addWidget(closingValueSpinBox,1,1);

    // Add widgets into "flagLayout"
    flagLayout->addWidget(isUseNucleusForMembrane);
    flagLayout->addWidget(isEllipsoidFit);

    // Add layouts into "optionsContent" layout
    optionsContent->addLayout(imageNameLayout);
    optionsContent->addLayout(membraneThresholdLayout);
    optionsContent->addLayout(closingValueLayout);
    optionsContent->addLayout(flagLayout);

    //
    options->setLayout(optionsContent);

    // ////// Management of the layout "options" - End


    // ////// Management of the layout "advanced" - Start

    // Create the layouts to be contained in "advanced"
    advancedContent = new QVBoxLayout;
    referenceImageMembranePathLayout = new QGridLayout;
    referenceImageScaffoldPathLayout = new QGridLayout;

    // Create widgets to be contained in "referenceImageMembranePathLayout"
    labelReferenceImageMembrane = new QLabel;
    labelReferenceImageMembrane->setText("Choose a custom reference image for the membrane");
    referenceImageMembranePath = new QLineEdit;
    browseReferenceImageMembrane = new QPushButton;
    browseReferenceImageMembrane->setText("browse");
    QObject::connect(browseReferenceImageMembrane,SIGNAL(clicked(bool)),this,SLOT(selectReferenceImageMembraneDialog()));

    // Create widgets to be contained in "referenceImageScaffoldPathLayout"
    labelReferenceImageScaffold = new QLabel;
    labelReferenceImageScaffold->setText("Choose a custom reference image for the scaffold");
    referenceImageScaffoldPath = new QLineEdit;
    browseReferenceImageScaffold = new QPushButton;
    browseReferenceImageScaffold->setText("browse");
    QObject::connect(browseReferenceImageScaffold,SIGNAL(clicked(bool)),this,SLOT(selectReferenceImageScaffoldDialog()));

    // Add widgets into "referenceImageMembranePathLayout"
    referenceImageMembranePathLayout->addWidget(labelReferenceImageMembrane,0,0);
    referenceImageMembranePathLayout->addWidget(referenceImageMembranePath,1,0);
    referenceImageMembranePathLayout->addWidget(browseReferenceImageMembrane,1,1);

    // Add widgets into "referenceImageScaffoldPathLayout"
    referenceImageScaffoldPathLayout->addWidget(labelReferenceImageScaffold,0,0);
    referenceImageScaffoldPathLayout->addWidget(referenceImageScaffoldPath,1,0);
    referenceImageScaffoldPathLayout->addWidget(browseReferenceImageScaffold,1,1);

    // Add layouts into "advancedContent" layout
    advancedContent->addLayout(referenceImageMembranePathLayout);
    advancedContent->addLayout(referenceImageScaffoldPathLayout);

    //
    advanced->setLayout(advancedContent);

    // ////// Management of the layout "advanced" - End


    // Add the three principal widgets into the main layout
    mainLayout->addWidget(paths);
    mainLayout->addWidget(options);
    mainLayout->addWidget(advanced);

    // Adds "Ok" and "Cancel" to the main layout
    mainLayout->addLayout(okCancelLayout);

    // Defines "mainLayout" as the layout of the GUI window
    this->setLayout(mainLayout);
}

// ////// Custom Slots

// Slot called when widget "browseWorkspace" is pressed - open a file browser to select a workspace
void GUI::selectWorkspaceDialog()
{
    QString folder = QFileDialog::getExistingDirectory(this,tr("Choose your workspace"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    workspacePath->setText(folder);
}

// Slot called when widget "browseOutputDirectories" is pressed - open a file browser to select a output directories location
void GUI::selectOutputDirectoriesDialog()
{
    QString folder = QFileDialog::getExistingDirectory(this, tr("Choose your output directories location"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    outputDirectoriesPath->setText(folder);
}

// Slot called when widget "browseDeconvolvedFolder" is pressed - open a file browser to select a deconvolved folder
void GUI::selectDeconvolvedFolderDialog()
{
    QString folder = QFileDialog::getExistingDirectory(this,tr("Select your deconvolved folder"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QStringList splitPath = folder.split('/');
    if (splitPath.isEmpty()) {
        deconvolvedFolderPath->setText("");
    } else {
        deconvolvedFolderPath->setText(splitPath.last());
    }

}

// Slot called when widget "browseReferenceImageMembrane" is pressed - open a file browser to select a reference image for the membrane
void GUI::selectReferenceImageMembraneDialog()
{
    QString folder = QFileDialog::getOpenFileName(this,tr("Choose your custom reference image for membrane segmentation"));
    referenceImageMembranePath->setText(folder);
}

// Slot called when widget "browseReferenceImageScaffold" is pressed - open a file browser to select a reference image for the scaffold
void GUI::selectReferenceImageScaffoldDialog()
{
    QString folder = QFileDialog::getOpenFileName(this,tr("Choose your custom reference image for scaffold segmentation"));
    referenceImageScaffoldPath->setText(folder);
}

// Slot called when "Ok" is pressed - Transfer information into a text file
void GUI::sendInfoToFile()
{
    // Get mandatory information from the widgets
    workspace = workspacePath->text();
    outputDirectories=outputDirectoriesPath->text();
    deconvolvedFolder=deconvolvedFolderPath->text();
    referenceImageMembrane=referenceImageMembranePath->text();
    referenceImageScaffold=referenceImageScaffoldPath->text();

    // Check if a mandatory information is missing
    if (workspace.isEmpty() || outputDirectories.isEmpty() || outputDirectoryLine->text().isEmpty() || voxelSizeXLine->text().isEmpty() || voxelSizeYLine->text().isEmpty() || voxelSizeZLine->text().isEmpty() || (!membraneCheckBox->isChecked() && !paxilinCheckBox->isChecked() && !nucleusCheckBox->isChecked() && !scaffoldCheckBox->isChecked())) {
        QMessageBox::information(this, "", "Please setup : \n - a workspace \n - an output directory location \n - an output directory name \n - a voxel size \n - select at least one channel");
    } else if (outputDirectories.contains(workspace)) {
        QMessageBox::information(this,"","Output directories location must not be in Workspace");
    } else {
    // Write mandatory information into file whose path is "inputParametersFilePath"
    std::ofstream outfile (inputParametersFilePath);
    outfile << workspace.toUtf8().constData() << std::endl;
    outfile << deconvolvedFolder.toUtf8().constData() << std::endl;
    outfile << outputDirectories.toUtf8().constData() << std::endl;
    outfile << outputDirectoryLine->text().toUtf8().constData() << std::endl;
    outfile << voxelSizeXLine->text().toUtf8().constData() << std::endl;
    outfile << voxelSizeYLine->text().toUtf8().constData() << std::endl;
    outfile << voxelSizeZLine->text().toUtf8().constData() << std::endl;

    // Write other information into the file
    if (membraneCheckBox->isChecked()) {
        outfile << 1 << std::endl;
    } else {
        outfile << 0 << std::endl;
    }
    outfile << membraneChannel->currentText().toUtf8().constData() << std::endl;
    if (paxilinCheckBox->isChecked()) {
        outfile << 1 << std::endl;
    } else {
        outfile << 0 << std::endl;
    }
    outfile << paxilinChannel->currentText().toUtf8().constData() << std::endl;
    if (nucleusCheckBox->isChecked()) {
        outfile << 1 << std::endl;
    } else {
        outfile << 0 << std::endl;
    }
    outfile << nucleusChannel->currentText().toUtf8().constData() << std::endl;
    if (scaffoldCheckBox->isChecked()) {
        outfile << 1 << std::endl;
    } else {
        outfile << 0 << std::endl;
    }
    outfile << scaffoldChannel->currentText().toUtf8().constData() << std::endl;
    outfile << imageNameLine->text().toUtf8().constData() << std::endl;
    outfile << membraneThresholdSpinBox->value() << std::endl;
    outfile << closingValueSpinBox->value() << std::endl;
    if (isUseNucleusForMembrane->isChecked()) {
        outfile << 1 << std::endl;
    } else {
        outfile << 0 << std::endl;
    }
    if (isEllipsoidFit->isChecked()) {
        outfile << 1 << std::endl;
    } else {
        outfile << 0 << std::endl;
    }
    outfile << referenceImageMembrane.toUtf8().constData() << std::endl;
    outfile << referenceImageScaffold.toUtf8().constData() << std::endl;
    outfile.close();
    QApplication::quit();
    }
}

// Slot called when "Cancel" is pressed - Close the GUI
void GUI::quitWhenCancel()
{
    std::ofstream outfile (inputParametersFilePath);
    outfile << "CANCEL" << std::endl;
    QApplication::quit();
}


