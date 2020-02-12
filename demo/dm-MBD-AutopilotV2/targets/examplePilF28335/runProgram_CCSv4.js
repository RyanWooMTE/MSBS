/*******************************************************************
 * examplePilF28335: runProgram_CCSv4.js
 *
 * Used by f28335pil.Launcher to download and run the executable.
 *
 * This Java script is passed as an argument to the Debug Server Scripting 
 * (dss) utility which ships with Code Composer Studio v4 (CCSv4).
 *
 * Usage:
 *   dss runProgram_CCSv4.js targetConfig.ccxml programName.out
 *
 *   dss:                 Utility which ships with CCSv4
 *   runProgram_CCSv4.js: This file
 *   targetConfig.ccxml:  CCSv4 target configuration file, specifically
 *                        f28335_ezdsp.ccxml for examplePilF28335
 *   programName.out:     Name of executable to download
 *   successFileName.txt: File which will be written upon success
 *
 * Reference:
 *	 http://processors.wiki.ti.com/index.php/Automating_CCS 
 *
 *******************************************************************
 * Copyright 2011 The MathWorks, Inc.
 *******************************************************************/

// Import the DSS packages into the namespace
importPackage(Packages.com.ti.debug.engine.scripting);
importPackage(Packages.com.ti.ccstudio.scripting.environment);
importPackage(Packages.java.lang);

// Get the input parameters
var targetConfig;           // First user input
var programName;            // Second user input
var successFileName;        // Third user input

var arguments = this.arguments;

if (!(arguments.length == 3))
{
    print(
        "ERROR: You did not specify the required arguments.\n" + 
        "Usage: dss runProgram.js <targetConfig> <programName>\n");        
    delete args;
    java.lang.System.exit(0);
}
targetConfig = arguments[0];
programName  = arguments[1];
successFileName = arguments[2];

// Create the scripting environment object
var script = ScriptingEnvironment.instance();

// Set the time out to (value of 1 = 1 msec)
script.setScriptTimeout(30000);

// Set up the debug session
print("*** Starting debug session...");

// Get the Debug Server
debugServer = script.getServer("DebugServer.1");
debugServer.setConfig(targetConfig);

// Start a Debug Session
debugSession = debugServer.openSession(".*");
print("*** Debug Session Name: " + debugSession.getName());
print("*** Board Name: " + debugSession.getBoardName());
print("*** CPU Name: " + debugSession.getCPUName());

// Connect to the target
try {
    print("*** Connecting to target...")
    debugSession.target.connect();
} 
catch (ex) {
    // ignore if connect() fails - it may not be supported    
}
//pause(2)
//print("*** Begin waiting...")
//    Thread.currentThread().sleep(3000);
//print("*** End waiting...")

// Reset the target
debugSession.target.reset();

// Load the program
print("*** Loading the program to the target...")
debugSession.memory.loadProgram(programName);

// Restart the program
debugSession.target.restart();

// Run the program
debugSession.target.runAsynch();

if (debugSession.target.isHalted()) {
    print("*** Program failed to run. Exiting...");
    //exitScript();
    //quit();
    java.lang.System.exit(0);
}
else {
    f = new java.io.File(successFileName);
    f.createNewFile();
    print("*** Program is running.");
}

// Wait forever
while(1){}

