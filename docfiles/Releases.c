/**
@page ReleaseDescriptions Release Descriptions
@section Version_1_1_7 version 1.1.6 - the "From The Heart" release
@subsection Features_1_1_7 New Features
- Added two subgraph queries to assimcli
- Changed <i>drawwithdot</i> to use subgraph queries - much faster results
- Added support for Docker containers
- Added support for Vagrant VMs
- Updated to Neo4j 3.0.1
- Updated to Py2neo 2.0.8
@subsection BugFixes_1_1_7 Bug Fixes
<i>none</i>
@subsection Caveats_1_1_7 Caveats
- Neo4j requires Java 1.8 - this eliminates some platforms
- Not compatible with database formats before 1.1.0
- No alerting, or interface to existing alerting beyond a sample email script. (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- Our current process only allows us to create 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and Debian, SuSE and 7.0 and later versions of CentOS.


@subsection Features_1_1_6 New Features
- Added several <a href="https://trello.com/c/G1DSBE6U">queries for installed packages</a>
- <a href="https://trello.com/c/s4vLO6Cv">Incorporate severities</a> into best practice score calculations.
- Added <a href=https://trello.com/c/9NxqFAGG"">OUIs to some MAC queries</a>
- Added <a href="https://trello.com/c/10HLSbEP">DNS/hosts names to some IP queries</a>
- Added a <a href="https://trello.com/c/IPIE00rw">query for MAC addresses without OUIs</a>
- Added a <a href="https://trello.com/c/qeEpY0wY">query for IP addresses without DNS/hosts names</a>
- Collect file ownership, permissions for system files
- Added <a href="https://trello.com/c/py1Eo7RT">security rules for password, group and shadow file permissions.</a>
- Added an <a href="https://trello.com/c/ceIgGgZI">/etc/sudoers best practice rule</a>
- Added <a href="https://trello.com/c/K6c0Qevr">security notifications to our sample email tool.</a>
- Added <a href="https://trello.com/c/KsGkBqTz">capability to make python queries be usable the same way as pure Cypher queries.</a>
- Moved test infrastructure <a href="https://trello.com/c/oXM25X6e">from Testify to py.test</a>

@subsection BugFixes_1_1_6 Bug Fixes
- <tt>assimcli loadqueries</tt> <a href="https://trello.com/c/cXc5wweQ">accepted bad JSON</a>
- Neo4j OCF monitoring agent now <a href="https://trello.com/c/ItD29HS0">works with Neo4j database with authentication enabled</a>.
- fixed "<a href="https://trello.com/c/tDQI98Au">Unterminated quoted string"</a> in <i>installme</i> installer
- fixed the numbering of a NIST/DISA best practice.

@subsection Caveats_1_1_6 Caveats
- a few options were shuffled for <i>assimcli query</i> score reporting queries.
- Not compatible with database formats before 1.1.0
- No alerting, or interface to existing alerting beyond a sample email script. (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- Our current process only allows us to create 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and Debian, SuSE and 7.0 and later versions of CentOS.

@section Version_1_1_4 version 1.1.4 - the April Fools Release (not a joke)
@subsection Features_1_1_4 New Features
- Recognize and automatically monitor Oracle
- Added new argmatch() function for returning a portion of a string matching a () regex
- Added support for IPv4-only systems (whether disabled by either known method)
- Added support for systems which create pidfile directories for us
- README updates
- Updated documentation to reflect use of GitHub instead of Mercurial (hurray!)
- Updated basic coding standards documentation
- Added yet-another-RedHat clone to the installer (and made that process easier)
@subsection BugFixes_1_1_4 Bug Fixes
- <i>none</i>
@subsection Caveats_1_1_4 Caveats
- Not compatible with database formats before 1.1.0
- No alerting, or interface to existing alerting beyond a sample email script.(hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- Our current process only allows us to create 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.

@section Version_1_1_3 version 1.1.3 - the Leap Day Release
@subsection Features_1_1_3 New Features
- We now work with (and enable) Neo4j authentication
- Added the drawwithdot command - draw pictures of subsets of the graph data
- Improved LLDP data capture (including LLDP-MED)
- Added test code for LLDP and CDP packet handling
- Added best practice scoring system
- Added three new canned best practice score reports (queries)
- Added discovery of the contents of /etc/auditd.conf
- Added auditd.conf best practice rules
- Added new assimcli subcommand for printing scores summarized by discovery type
- Added new assimcli subcommand for printing scores summarized by discovery type and hostname
- Added new assimcli subcommand for printing scores summarized by discovery type and ruleid
  The new subcommands and queries are great for planning security/compliance triage

@subsection BugFixes_1_1_3 Bug Fixes
- Fixed a bug in conversion of JSON floating point numbers
- Made CDP data capture work
- Made discovery code obey timeout and warntime directives
- Fixed checksum program default configuration
@subsection Caveats_1_1_3 Caveats
- Not compatible with database formats before 1.1.0
- **Documentation has not been updated to reflect move to github.** No doubt other shortcomings exist as well. Sorry! Please fix and generate a pull request.
- No alerting, or interface to existing alerting beyond a sample email script.(hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- Our current process only allows us to create 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.

@section Version_1_1_2 version 1.1.2 - the Happy 2016 release
@subsection Features_1_1_2 New Features
- Now produce packages and installer works on openSUSE
- best practice compliance code now issues warn and unwarn events
- new code for debugging bad key id problems
- added overview documentation of cma python files
- you can now say "make tests" to run tests
- changed libsodium RPM dependency to not be so particular about the version of libsodium available
- added support for scientific and scientificfermi linux
- enabled /etc/sudoers discovery by default

@subsection BugFixes_1_1_2 Bug Fixes
- discovery of /proc/sys now ignores I/O errors (this happens on some newer kernels)
- linux os discovery won't issue funky messages when lsb_release is not installed
- assimcli now works with a non-empty database again
- fixed sudoers command to support += operator

@subsection Caveats_1_1_2 Caveats
- Not compatible with database formats before 1.1.0
- Documentation has not been updated to reflect move to github. No doubt other shortcomings exist as well. Sorry! Please fix and generate a pull request.
- No alerting, or interface to existing alerting beyond a sample email script (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- use with recent versions of Neo4j requires disabling authentication on Neo4j
- Our current process only allows us to create 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.

@section Version_1_1_1 version 1.1.1 - the Thanksgiving Release
@subsection Features_1_1_1 New Features
- Added sample notification API client code - https://trello.com/c/LmBhODaa
- Added --remote option to the installer - https://trello.com/c/P2czyw9x
@subsection BugFixes_1_1_1 Bug Fixes
- Fixed notification API filter code - https://trello.com/c/RFpMIIhP
- Fixed switch discovery - https://trello.com/c/ZJacf7EI
- Fixed installer to not remove file that doesn't exist - https://trello.com/c/5RcOfd3H
@subsection Caveats_1_1_1 Caveats
- Not compatible with database formats before 1.1.0
- Sudoers discovery is disabled for this release - will reappear later on
- Documentation has not been updated to reflect move to github. No doubt other shortcomings exist as well. Sorry! Please fix and generate a pull request.
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- use with recent versions of Neo4j requires disabling authentication on Neo4j
- performance with Neo4j is poor. Strangely, it's not a scalability problem. Fixes will be in a future release.
- Best practices alerts currently only come out in syslog - not as events. Sorry!
- Our current process only allows us to create 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.
- The magic installer can't install CMAs onto Fedora due to Neo4j dependency issues.

@section Version_1_1_0 version 1.1.0 - the MCH Release
<b>Special Note</b> This release cannot make use of older databases. The workaround is to start the CMA <i>one time</i> with the --cleandb flag, and restart all your nanoprobes. Sorry about that.
This release is named after my Father-in-law - whose 94th birthday was 1 November 2015. Happy Birthday!
@subsection BugFixes_1_1_0 Bug Fixes
- Installer now locks down the version of Neo4j RPMs it installs. https://trello.com/c/o2KPR0aB 
- Made the code stop barfing on Neo4j beta release version numbers https://trello.com/c/eTwkkWMI
- Ensured that built releases have the right version number everywhere https://trello.com/c/cc8k892c
- Changing MAC/IP association no longer makes the CMA sick https://trello.com/c/ySlAkWJC
- README.md fixes
@subsection Features_1_1_0 New Features
- <i>Significant</i> performance improvement for accessing Drone (server) nodes in the database. https://trello.com/c/p19w7Jyn
- Added a best practice rule to discourage tunnelled ssh passwords.
- Verified operation against Neo4j 2.3.0 - and changed installer to favor that release. https://trello.com/c/nHUuTNUT
- Register installations via Google forms https://trello.com/c/jGsV4dt4
@subsection Caveats_1_1_0 Caveats
- Not compatible with previous database formats.
- Sudoers discovery is disabled for this release - will reappear later on
- Documentation has not been updated to reflect move to github. No doubt other shortcomings exist as well. Sorry! Please fix and generate a pull request.
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- use with recent versions of Neo4j requires disabling authentication on Neo4j
- performance with Neo4j is poor. Strangely, it's not a scalability problem. Fixes will be in a future release.
- Best practices alerts currently only come out in syslog - not as events. Sorry!
- Our current process only allows us to distribute 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.
- The magic installer can't install CMAs onto Fedora.

@section Version_1_0_2 version 1.0.2 - the "pre-Columbus Day" release - 08 October 2015
This is a bug-fix-only release of things discovered once we got more people to install it with the easy-installer
@subsection BugFixes_1_0_2 Bug Fixes
- Added net-tools dependency for CentOS >= 7
- Worked around brain-dead-bug in systemd
- Fixed bug around iterable Drone objects which caused some discovery to be ignored.
- Fixed broken links on the web site
- Created directories for nanoprobe pid file
- Fixed ldconfig typo in RPM packages
- Added '.' character as permissible system name
- Increased maximum system name length
- Disabled sudoers discovery to avoid periodic errors
@subsection Features_1_0_2 New Features
- <i>none</i>
@subsection Caveats_1_0_2 Caveats
- Sudoers discovery is disabled for this release - will reappear later on
- Documentation has not been updated to reflect move to github. No doubt other shortcomings exist as well. Sorry! Please fix and generate a pull request.
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- use with recent versions of Neo4j requires disabling authentication on Neo4j
- performance with Neo4j is poor. Strangely, it's not a scalability problem. Fixes will be in a future release.
- Best practices alerts currently only come out in syslog - not as events. Sorry!
- Our current process only allows us to distribute 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.
- The magic installer can't install CMAs onto Fedora.

@section Version_1_0_1 version 1.0.1 - the "Day 30" release - 30 September 2015
@subsection Features_1_0_1 New Features
- Moved development to git and github
- Continuous integration via travis-ci
- Awesome universal installer - run this script to install a CMA or nanoprobe system and be happy. Will install any of the systems handling everything.
- Building includes 10(!) 64-bit platforms:
 - Ubuntu precise, trusty, vivid, and wily.
 - Debian jessie and wheezy.
 - CentOS 6 and 7.
 - Fedora 21 and 22.
- Added over 40 best practice rules from the <a href="http://ITBestPractices.info>IT Best Practices project</a>. Most are security rules, but one is a networking rule. These include DISA rules for:
 - PAM
 - /proc/sys
 - sshd
 - /etc/login.defs
 - many more to come in the future!
- increased maximum host name length so it doesn't barf on 56-character host names(!) in travis-ci.
- added the loadbp command to load best practices
- perform checksums over all known checksum programs
- made list of default checksum files be configurable
- updated it to work with newer version of Neo4j and py2neo version 2.x
- improved the process for putting out a release so that everything is consistent and is marked with the right version number.
- Added discovery for /etc/sudoers
- Added travis-ci and coverity badges to github site.
@subsection BugFixes_1_0_1 Bug Fixes
- bug in partitions discovery agent
- bug in mdadm discovery agent
- fixed UnknownIPs query
- removed duplicates from the allips query
- discovery test failures didn't cause overall test results to be marked as failed
- several discovery tests weren't quite right.
@subsection Caveats_1_0_1 Caveats
- Documentation has not been updated to reflect move to github. No doubt other shortcomings exist as well. Sorry! Please fix and generate a pull request.
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA will suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- use with recent versions of Neo4j requires disabling authentication on Neo4j
- performance with Neo4j is poor. Strangely, it's not a scalability problem. Fixes will be in a future release.
- Best practices alerts currently only come out in syslog - not as events. Sorry!
- Our current process only allows us to distribute 64-bit binaries. Feel free to build 32-bit binaries yourself. They still work for Ubuntu, and probably Debian and 7.0 and later versions of CentOS.
- The magic installer can't install CMAs onto Fedora.

@section Version_1_0 version 1.0 - the "Independence Day" release - 4 July 2015
This release provides a number of new features, and a number of bug fixes.
This release is eminently suitable for deployments in environments where the caveats are acceptable.
We have quite a few pre-built Ubuntu packages, and a few CentOS/RHEL packages for this version in the 1.0 subdirectory of 
http://bit.ly/assimreleases.
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v1.0.tar.gz
@subsection Features_1_0 New Features
- Support for <a href="https://trello.com/c/gBvVYLfFP">Nagios remote agent APIs</a> from Carrie Oswald <carrieao@comcast.net>.
  Not all Nagios agents are automatically configured, some are duplicates of generally superior OCF resource agents.
  You can easily add configuration for anything you want Nagios to monitor.
  This version includes automatic configuration of the following Nagios agents:
 - check_load (load average)
 - sensors (checking for temperatures, fan speeds, etc)
 - sshd (secure shell daemon/service)
- Added nagios to the set of discovery agents we discover using the monitoringagents discovery agent.
- Optimize initial nanoprobe setup time by <a href="https://trello.com/c/uIwMlDxQ">combining all the ARP and switch discovery requests into one packet</a>.
  In addition to being a significant optimization, it is also required for systems with large numbers of interfaces to avoid queue overflow.
- Provided some initial API documentation
- New discovery agents: PAM, /proc/partitions, mdadm, findmnt, nsswitch, commands, sshd configuration.
- Prototype (toy) code for evaluating best practices (security, network, etc.).
- <a href="https://trello.com/c/eq3Jn6Rf">added the location of where to report bugs to the web site</a>.
- Added a download link to the top right of every page. Thanks to Dimitri van Heesch for teaching us how to do that.
-  <a href="https://trello.com/c/0pcKwdLK"> Eliminated a number of redundant startup messages.</a>
- Minor change to allow us to build under docker for precise, trusty, utopic, and vivid
- Added a number of new unit test cases - particularly for discovery agents.

@subsection BugFixes_1_0 Bug Fixes
- <a href="https://trello.com/c/nmbxX6kY">Flask queries with parameters don't work</a> - also added code to limit the max size of JSON_ node attributes in query results.
- <a href="https://trello.com/c/3tIhv3Jp">pcap_lookupnet() failure should not be fatal</a>
- <a href="https://trello.com/c/Htc1T9H9">Timestamps in discovery results were never set</a>.
- <a href="https://trello.com/c/upkwQiZA">Code was not listening to ARP or LLDP/CDP packets</a>.
  This probably wasn't an issue in the last release, but got introduced between releases.
- <a href="https://trello.com/c/AxcvC9zW">resources monitored by invalid monitoring requests aren't marked as down</a>.
  This only can occur when the CMA and nanoprobe versions are out of sync with each other - like in the middle of adding nagios support for example ;-).
- Fixed a number of bugs associated with testing (not real code bugs).
- Corrected a number of dependencies for building and final packages.

@subsection Caveats_1_0 Caveats
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- queries could benefit from more indexes for larger installations.
- The CMA may suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
- use with recent versions of Neo4j requires disabling authentication on Neo4j

@section Version_0_5 version 0.5 - the "Valentine's day" release - 14 February 2015
This is release is sixth in a series of releases intended to culminate in an awesomely useful release.
It is primarily a bug fix release.
This release is eminently suitable for deployments in environments where the caveats are acceptable.
We have quite a few pre-built Ubuntu packages, and a few CentOS/RHEL packages for this version in the 0.5 subdirectory of 
http://bit.ly/assimreleases.
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v0.5.tar.gz
@subsection Features_0_5 New Features
- We now produce Docker images for several versions of Linux, suitable for doing demos, testing, and learning about the software.
@subsection BugFixes_0_5 Bug Fixes
- Fixed a bug where command line (assimcli) queries sometimes failed due to interactions with Linux security modules
- Fixed a longstanding-but-previously-unknown bugs where it didn't like floating point numbers or negative integers in JSON
@subsection Caveats_0_5 Caveats
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- the queries need to have more indexes for larger installations.
- The CMA may suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI
@section Version_0_1_5- version 0.1.5 - the 'secure communications' release - 29 January 2015
This is the fifth in a series of releases intended to culminate in an awesomely useful release.
This release is eminently suitable for actual deployments in an environment where the caveats are acceptable.
We have quite a few pre-built Ubuntu packages, and a few CentOS/RHEL packages for this version in the 0.1.5 subdirectory of 
http://bit.ly/assimreleases .
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v0.1.5.tar.gz
@subsection Features_0_1_5 New Features
- Encrypted Communication.  Communication between the CMA and nanoprobes are now strongly encrypted using curve25519.
- Added <tt>genkeys</tt> option to <tt>assimcli</tt>
- Added new queries to <tt>assimcli</tt>
- Added discovery of /proc/sys data
- Added feature for debugging in the field (circular FSA buffer)
- Increased kernel buffering for the CMA
- Improved system testing code
- Improved scrubbing of network packets
- Improved diagnostics on startup failures
- Added the ability to take core dumps to the CMA and nanoprobe init scripts
@subsection BugFixes_0_1_5 Bug Fixes
- Several protocol holes were plugged.
- Fixed coverity-flagged issues: 1262409, 1262410, 1262411, 1262412, 1262413
- Fixed a few queries in <tt>assimcli</tt>
@subsection Caveats_0_1_5 Caveats
- No alerting, or interface to existing alerting (hooks to build your own interface are included)
- high availability option for the CMA is roll-your-own using Pacemaker or similar
- the queries need to have more indexes for larger installations.
- The CMA may suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- no GUI

@section Version_0_1_4- version 0.1.4 - the 'much better tested' release - 20 October 2014
This is the fourth in a series of releases intended to culminate in a truly useful release.
This release is eminently suitable for trials in an environment where the caveats are acceptable.
We have quite a few pre-built Ubuntu packages, and a few CentOS/RHEL packages for this version in the 0.1.4 subdirectory of 
http://bit.ly/assimreleases .
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v0.1.4.tar.gz

A complete and detailed view of the features, bugs, caveats and so on for the Assimilation
Project is currently held on on <a href="https://trello.com/b/98QrdEK1/issues-bugs">Trello</a>.
The lists of special interest are the <b>In release 0.4</b> list and the various other bug and caveat lists in
<a href="https://trello.com/b/98QrdEK1/issues-bugs">this board</a>.

@subsection Features_0_1_4 Features
- 100+ system System-level testing environment now part of development process
- We now create several CentOS packages in our official build environment
- Added support for Cisco's CDP (Cisco Discovery Protocol) for discovering switch connections in Cisco environments
- Builds now support RHEL6/7 environments
- Detailed documentation on building and installing for RHEL6.
- ARP IP/MAC discovery on multiple interfaces (previously hard-wired to eth0)
- LLDP/CDP discovery on multiple interfaces (previously hard-wired to eth0)
- Added timeouts to discovery processes
- Canned queries can now return simple (non-node) values.
- Bugs and features in this release now logged in <a href="https://trello.com/b/98QrdEK1/issues-bugs">Trello</a>.
- Documentation updates.

@subsection BugFixes_0_1_4 Bug Fixes
- Several canned queries now fixed
- Removed duplicate ipport entries in database
- Nanoprobes now stop reliably
- ARP discovery flooding now mitigated
- Numerous fixes related to the reliable communications protocol
- Numerous other small fixes.

@subsection Caveats_0_1_4 Caveats
- communication is neither authenticated nor confidential
- No alerting, or interface to alerting (hooks to build your own interface are included)
- high availability option for the CMA
- the queries need to have more indexes for larger installations.
- statistical data collection
- The CMA may suffer performance problems when discovering IP addresses when large numbers of nanoprobes are on a subnet.
- Object deletion not yet reliable or complete

Features that are expected for a monitoring solution but are <b>not</b> included include these:
- useful alerting (but you can probably integrate your own)
- Alerting history.
- non-Linux system support (POSIX and Windows - but now someone is working on Windows!)
- statistical data collection
Note that these features are understood to be important and are planned - but this release
does not include them.

@section Version_0_1_3- version 0.1.3 - the 'even more interesting' release - 02 May 2014 [32 April 2014;-)]
This is the third in a series of releases intended to culminate in a truly useful release.
This release is suitable for trials in an environment where the caveats are acceptable.
We have quite a few pre-built Ubuntu packages for this version here:
https://www.dropbox.com/sh/4olv5bw1cx8bduq/AADYcxtYYwlFZxV-P0LpRA4ra/builds/Releases/0.1.3
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v0.1.3.tar.gz
@subsection Features_0_1_3 Features
These features are new with release 0.1.3.
- ARP discovery - we listen to ARP packets (including broadcasts) and add the IP addresses we find to the CMDB
- Package discovery - we discover what packages you have installed and add the results to the database
- Packet compression - we now allow discovery packets of JSON up to about 300K through compression.
- Works on CentOS 6.5 and related RedHat-derived systems
- Works on Fedora 20 (and probably other Fedora releases as well)
- Updated documentation - GettingStarted (thanks Ken Schumacher) and other places
- Dockerfiles for Fedora and CentOS
@subsection BugFixes_0_1_3 Bug Fixes
- Fixed problems which kept strict compilation flags from being used
@subsection Caveats_0_1_3 Caveats
- Object deletion not yet reliable or complete
- No alerting, or interface to alerting (hooks to build your own interface are included)
- communication is neither authenticated nor confidential
- heterogeneous system support (POSIX and Windows - but now someone is working on Windows!)
- statistical data collection
- CDP support for Cisco switch discovery
- high availability option for the CMA
- the queries need to have more indexes for larger installations.

Features that are expected for a monitoring solution but are <b>not</b> included include these:
- useful alerting (but you can probably integrate your own)
- heterogeneous system support (POSIX and Windows - but someone is now looking at Windows - yay!)
- statistical data collection
Note that these features are understood to be important and are planned - but this first release
does not include them.

@section Version_0_1_2- version 0.1.2 - the 'very interesting' release - 20 March 2014
These features are new with release 0.1.3.
This is the second in a series of releases intended to culminate in a truly useful release.
This release is suitable for limited trials in an environment where the caveats are acceptable.
you can find quite a few pre-built Ubuntu packages for this version here: https://www.dropbox.com/sh/h32lz3mtb8wwgmp/26AyspFaxL/Releases/0.1.2
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v0.1.2.tar.gz
@subsection Features_0_1_2 Features
These features are new with release 0.1.2.
- added <i>assimcli</i> - a command line query tool with more than 15 cool canned queries.  These queries are also available through the REST interface.
 - allipports:     get all port/ip/service/hosts
 - allips: get all known IP addresses
 - allservers:     get known servers
 - allservicestatus:       status of all monitored services
 - allswitchports: get all switch port connections
 - crashed:        get 'crashed' servers
 - down:   get 'down' servers
 - downservices:   get 'down' services
 - findip: get system owning IP
 - findmac:        get system owning MAC addr
 - hostdependencies:       host's service dependencies
 - hostipports:    get all port/ip/service/hosts
 - hostservicestatus:      monitored service status on host
 - hostswitchports:        get switch port connections
 - list:   list all queries
 - shutdown:       get gracefully shutdown servers
 - unknownips:     find unknown IPs
 - unmonitored:    find unmonitored services
- added a checksum monitoring capability - for network-facing binaries, libraries and JARs.
- updated to a newer and faster version of the py2neo library
- updated the CMA to use the Glib mainloop event scheduler
- added a certain amount of Docker compatibility.  Assimilation now builds and installs correctly for CentOS 6 (but some tests seem to fail).

@subsection BugFixes_0_1_2 Bug Fixes
- Fixed the memory leak from 0.1.1 - which turned out to be minor.
- Fixed a subtle bug in the Store class where it would appear to lose values put into node attributes
- Fixed lots of bugs in the REST queries - and renamed them to be more command line friendly
@subsection Caveats_0_1_2 Caveats
- Object deletion not yet reliable or complete
- No alerting, or interface to alerting (hooks to build your own interface are included)
- communication is neither authenticated nor confidential
- heterogeneous system support (POSIX and Windows - but now someone is working on Windows!)
- statistical data collection
- CDP support for Cisco switch discovery
- high availability option for the CMA
- the queries need to have more indexes for larger installations.

Features that are expected for a monitoring solution but are <b>not</b> included include these:
- useful alerting (but you can probably integrate your own)
- heterogeneous system support (POSIX and Windows - but someone is now looking at Windows - yay!)
- statistical data collection
Note that these features are understood to be important and are planned - but this first release
does not include them.

@section Version0_1_1- version 0.1.1 - the 'possibly trial-worthy' release - 11 Feb 2013
This is the first in a series of releases intended to culminate in a truly useful release.
This release is suitable for limited trials in an environment where the caveats are acceptable.
You can find a few pre-built Ubuntu packages for this version here: https://www.dropbox.com/sh/h32lz3mtb8wwgmp/WZKH4OWw1h/Releases/0.1.1
A tar ball for this version can be found here: http://hg.linux-ha.org/assimilation/archive/v0.1.1.tar.gz

@subsection Features_0_1_1 Features
These features are new with release 0.1.1.
- new Neo4j schema
- service monitoring
- automatic (zero-config) service monitoring through templates
- basic fork/exec event notification feature - /usr/share/assimilation/notification.d
- hooks for more sophisticated event notification
- added Pylint analysis and verification
- added Coverity static analysis
- added root ulimit discovery
- added discovery of locally installed monitoring agents
- integration of all tests under testify
- added a Neo4j OCF resource agent
- added Flask code to support the creation of a JavaScript User Interface
- Added Query objects in support of the Flask code.
- Added the ability for for the Flask code to invoke Query objects and get results
- significant internal improvements in Neo4j access
- allow parsing of MAC addresses - they're now all in XX-YY-ZZ (etc) format.
- Added transactions for the database and the network
- removed "Monitoring" from the project name (but not from its capabilities)

@subsection BugFixes_0_1_1 Bug Fixes
- check to make sure requested discovery scripts are present before executing them
- much improved tcp service discovery
- fixed a number of 64-bit-only assumptions in the code and tests
- improved compatibility with old versions of Ubuntu
- All graph node creation now checks to see if it already exists - avoiding accumulating superfluous objects
- lots of other bugs associated with new features ;-)

@subsection Caveats_0_1_1 Caveats
- The CMA has a known slowish memory leak.  It'll still take it a long time to grow larger than a small Java program ;-)
  More importantly, it is very unlikely to happen <i>at all</i> in a production system.
- You will have to recreate your Neo4j database from scratch to convert to this release.
- Object deletion not yet reliable or complete
- No alerting, or interface to alerting (hooks to build your own interface are included)
- communication is neither authenticated nor private
- heterogeneous system support (POSIX and Windows)
- statistical data collection
- CDP support for Cisco switch discovery
- high availability option for the CMA

Features that are expected for a monitoring solution but are <b>not</b> included include these:
- useful alerting (but you can probably integrate your own)
- heterogeneous system support (POSIX and Windows)
- statistical data collection
Note that these features are understood to be important and are planned - but this first release
does not include them.

@section Version0_1_0- version 0.1.0 - the 'toy' release - 19 March 2013
The very first release of the <i>Assimilation Monitoring Project</i> - here at last!
The purpose of this Linux-only release is to get the code from this
revolutionary new architecture out there and get it in people's hands so
that they can evaluate the concepts, provide feedback, and find bugs.
It is highly recommended that you read the @ref GettingStarted documentation.
@subsection Features_0_1_0 Features
- easily extensible discovery mechanism
- Neo4J graph database documenting the data center configuration
- fully distributed, extremely lightweight, reliable monitoring
- <b>no</b> configuration needed for most environments - very simple configuration for all environments.
- basic <i>host</i> monitoring
- continuous, integrated stealth discovery of these kinds of information:
 - host network configuration - NICs, IP addresses, MAC addresses
 - host OS version information
 - basic hardware
 - ARP cache information
 - detailed information about TCP services offered (server role)
 - detailed information about TCP services consumed (client role)
 - LLDP-based server/switch topology discovery - which host NICs are connected to which switch ports
 - Tested extensively on Linux systems.
 - Source code known to compile on Windows systems (will eventually run there too).

Features that are expected for a monitoring solution but are <b>not</b> included include these:
- meaningful alerting
- service monitoring
- heterogeneous system support (POSIX and Windows)
- statistical data collection
- CDP support for switch discovery
- high availability option for the CMA

Note that these features are understood to be important and are planned - but this first release
does not include them.

@subsection BugFixes_0_1 Bug Fixes
Since this is the first release, you could consider everything a bug fix - or nothing -- take your pick.
@subsection Caveats_0_1 Caveats
This is the very first baby release of the project - nicknamed the <i>toy</i> release for a reason.
Although the code looks very stable for a release of this nature, and is unlikely to consume
vast quantities of resources or crash your machines - it has never seen real field action before -
and such results are not out of the realm of possibility for any software - much less
for software so new as this release.

It is recommended that you deploy this release on test machines until sufficient feedback has been
received to determine how it plays out in the field.

Other more mundane caveats:
- efficiency - the code is currently wildly inefficient compared to what it should be to achieve its scalability goals
  There are many known issues in this area.
- service discovery duplication
- no doubt many others which are not known, or have been forgotten about
- CMA restart might lose data from nanoprobes for discovery or system outages

*/
