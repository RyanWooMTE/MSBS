/*******************************************************************
 * examplePilF28335: initDrivers_CCSv4.js
 *
 * Used by to initialize driver communication.
 *
 * This Java script is passed as an argument to the Debug Server Scripting 
 * (dss) utility which ships with Code Composer Studio v4 (CCSv4).
 *
 * Usage:
 *   dss initDrivers_CCSv4.js targetConfig.ccxml
 *
 *   dss:                 Utility which ships with CCSv4
 *   initDrivers_CCSv4.js: This file
 *   targetConfig.ccxml:  CCSv4 target configuration file, specifically
 *                        f28335_ezdsp.ccxml for examplePilF28335
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
var debugSession;

var arguments = this.arguments;

if (!(arguments.length == 1))
{
    print(
        "ERROR: You did not specify the required arguments.\n" + 
        "Usage: dss initDriver_CCSv4.js <targetConfig>\n");        
    delete args;
    java.lang.System.exit(1);
}
targetConfig = arguments[0];

// Create the scripting environment object
var script = ScriptingEnvironment.instance();

// Set up the debug session
print("*** Starting debug session...");


try
{
    // Get the Debug Server
    debugServer = script.getServer("DebugServer.1");
    print("Using config: " + targetConfig);
    debugServer.setConfig(targetConfig);

    // Start a Debug Session
    debugSession = debugServer.openSession(".*");
    print("*** Debug Session Name: " + debugSession.getName());
    print("*** Board Name: " + debugSession.getBoardName());
    print("*** CPU Name: " + debugSession.getCPUName());
}
catch (err)
{
    throw "Could not start DebugServer.  Is the target properly configured?";
    java.lang.System.exit(1);
}
// Connect to the target
try {
    print("*** Connecting to target...")
    debugSession.target.connect();
} 
catch (ex) {
    // ignore if connect() fails - it may not be supported  
    print("*** ERROR Connecting to target...")  
}

// Reset the target
print("*** Resetting target...");
debugSession.target.reset();
print("*** Halting target...");
debugSession.target.halt();

print("*** Completed driver intialization");
java.lang.System.exit(0);

