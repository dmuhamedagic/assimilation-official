#!/usr/bin/python
'''
A collection of classes which provide constants for FrameTypes and FrameSetTypes
'''

import re
class pyFrame:
  pass
class pySignFrame:
  pass
class pyCryptFrame:
  pass
class pyCompressFrame:
  pass
class pySeqnoFrame:
  pass
class pyIntFrame:
  pass
class pyCstringFrame:
  pass
class pyAddrFrame:
  pass
class pyNVpairFrame:
  pass

class FrameTypes:
    'Class defining the universe of FrameSets - including code to generate a C header file'
    None
    fileheader = \
'''
/**
 * @file
 * @brief Header file defining the data layouts for our Frames.
 * THIS FILE MECHANICALLY GENERATED by "%s".  DO NOT EDIT.
 *
 * @author &copy; 2011,2012 - Alan Robertson <alanr@unix.sh>
 * @n
 * Licensed under the GNU Lesser General Public License (LGPL) version 3 or any later version at your option.
 * excluding the provision allowing for relicensing under the GPL at your option.
 *
 */
/**
@addtogroup FrameFormats
@{
  Below is the set of frame formats and corresponding macro definitions
  This section will document the format of the individual frame types.
  The first frame in a frameset must be a signature frame.
  If an encryption frame is present, it must be the  frame in the frameset.
  If a compression frame is present, it must occur after the encryption frame
  if present, or after the signature frame, if there is no encryption frame.
 
  The final frame in a frameset must be an End frame (which will be
  added automatically by the @ref FrameSet marshalling classes).
@}
*/
/**
@defgroup IndividualFrameFormats Individual TLV 'Frame' data types and layouts (by TLV type)
@{
Below is the set of individual frame types and data layouts - organized by TLV type.
Note that a given @ref Frame subclass can appear be associated with many different TLV types.
This file organizes this data by the TLV type, not by the underlying @ref Frame subclass.
@ingroup FrameFormats
@ingroup DefineEnums
@{
*/
'''
    asciiart = {
	'pyFrame':
'''
+----------------+-----------+------------------+
| frametype = %2d | f_length  |    frame data    |
|   (16 bits)    | (16-bits) | (f_length bytes) |
+----------------+-----------+------------------+
''',
	'pySignFrame':
'''
+----------------+-----------+-----------------+--------------------+
| frametype = %2d | f_length  | signature-type  | digital signature  |
|   (16 bits)    | (16-bits) | (16 bits)       | (f_length-2 bytes) |
+----------------+-----------+-----------------+--------------------+
''',
	'pyCryptFrame':
'''
+----------------+-----------+-------------------------+
| frametype = %2d | f_length  | encryption information  |
|   (16 bits)    | (16-bits) |     (f_length bytes)    |
+----------------+-----------+-------------------------+
''',
	'pyCompressFrame':
'''
+----------------+-----------+------------------------+
| frametype = %2d | f_length  | compression information|
|   (16 bits)    | (16-bits) |    (f_length bytes)    |
+----------------+-----------+------------------------+
''',
	'pySeqnoFrame':
'''
+----------------+---------------+-------------+-----------+
| frametype = %2d | f_length = 8  |  reply id   | queue id  |
|   (16 bits)    |   (16-bits)   |  (8 bytes)  | (2 bytes) |
+----------------+---------------+-------------+-----------+
''',

	'pyIntFrame':
'''
+----------------+--------------+-------------------------+
| frametype = %2d | f_length =   |     integer  value      |
|                | 1,2,3,4 or 8 |           value         |
|   (16 bits)    |   (16-bits)  |   (1,2,3,4,or 8 bytes)  |
+----------------+--------------+-------------------------+
''',
	'pyCstringFrame':
'''
+----------------+----------------+----------------+--------+
| frametype = %2d | f_length = 'n' | interface name |  0x00  |
|   (16 bits)    |    (16-bits)   |   (n-1 bytes)  | 1 byte |
+----------------+----------------+----------------+--------+
''',
	'pyAddrFrame':
'''
+----------------+----------------+---------------+--------------+
| frametype = %2d | f_length = n   | Address Type  |  address     |
|   (16 bits)    |    (16-bits)   |    2 bytes    | (n-2 bytes)  |
+----------------+----------------+---------------+--------------+
''',
	'pyNVpairFrame':
'''
+----------------+---------------+--------+-----------------+-------+------+
| frametype = %2d | f_length = n  | nm_len |  name    | NUL  |       | NUL  |
|   (16 bits)    |    (16-bits)  | 1 byte | nm_len-1 | byte | value | byte |
|                |               |(8 bits)|  bytes   |      |       |      |
+----------------+---------------+--------+-----------------+-------+------+
''',

}
    _intframetypes = {
  	0:  (pyFrame, 'END', 'Final frame in a message',
'''The last frame in a frameset is required to be an End frame.
End frames are of type zero and ALWAYS have length zero.
Its corresponding @ref Frame class is @ref Frame.
'''),
  	1:  (pySignFrame, 'SIG', 'Digital signature frame',
'''The signature frame is mandatory and must be the first
frame in the frameset - and must have frametype <b>1</b>.
The digital signature computed in the digital signature field is computed
on all the bytes in the frameset beginning with the first byte after
the end of this frame, extending through and including the last byte of the frameset.
Note that this will include the encryption frame if present.
The format and length of the digital signature depends on the type of signature.
'''),
  	2:  (pyCryptFrame, 'CRYPT', 'Encryption frame',
'''If an encryption frame is present it must be the second
frame in the frameset, and can only be preceded by a @ref FRAMETYPE_SIG frame.
It must have frametype <b>2</b>.
When this frame is present, then all the frames following
are encrypted according information in the encryption information value segment.
'''),
  	3:  (pyCompressFrame, 'COMPRESS', 'Compression frame',
'''If a compression frame is present (<b>frametype = 3</b>) it must be the second
or third frame in the frameset, and can only be preceded by a @ref FRAMETYPE_SIG
and @ref FRAMETYPE_CRYPT frames.
When this frame is present, then all the frames following
are compreseed according information in the compression information value segment.
The format of the compression information value segment will likely be a
single integer saying which compression method was used.
'''),
  	4:  (pySeqnoFrame, 'REQID', 'Request ID - a message sequence number.',
'''Requests from the central authority are identified by a request id
(basically a sequence number) and a queue id.  The combination of the two
is unique over a relatively long period of time - at least days.
Notifications from clients are sent with queue id 0, which will never be
used by the central authority.
'''),
  	5:  (pySeqnoFrame, 'REPLYID', 'Reply ID - a message sequence number.',
'''Requests from the central authority are identified by a request id
and a queue id.  Any reply id corresponds to an identical request ID.
'''),
  	6:  (pyFrame, 'PKTDATA', 'Encapsulated packet data',
'''This frame format is normally used for a CDP or LLDP packet.
The data is kept exactly as it was received from the
network interface via libpcap.
'''),
  	7:  (pyIntFrame, 'WALLCLOCK', '64-bit local time',
'''This frame provides local time on the sending system as gotten from the
g_get_real_time() call - which is a 64-bit time measured in microseconds.
In spite of the apparent variability permitted above, it is an 8-byte (64-bit) integer.
'''),
  	8:  (pyCstringFrame, 'INTERFACE', 'Name of network interface as a C-style string',
'''This frame provides the name of a network interface as a
NUL-terminated C-style string.
'''),
  	9:  (pyCstringFrame, 'HOSTNAME', 'Name of host as a C-style string',
'''This frame provides the name of a host as a NUL-terminated C-style string.
'''),
  	10:  (pyAddrFrame, 'IPADDR', 'IP address in either IPv4 or IPv6 format.',
'''IPv4 addresses are address type 1 and are 4 bytes long.
IPv6 addresses are address type 2 and are 16 bytes long, and have Address types 1 and 2 respectively.
'''),
  	11:  (pyAddrFrame, 'MACADDR', 'MAC Address.',
'''This frame can be either a 6 byte (EUI-48) or an 8 byte (EUI-64) format MAC address.
The Address Type for a MAC address is 6.
'''),
  	12:  (pyIntFrame, 'PORTNUM', 'Port number.',
'''This frame is a 16-bit IP port number.
'''),
  	13:  (pyIntFrame, 'HBINTERVAL', 'Heartbeat interval.',
'''This frame is a heartbeat sending interval measured in seconds.
'''),
  	14:  (pyIntFrame, 'HBDEADTIME', 'Heartbeat deadtime.',
'''This frame is a heartbeat deadtime measured in seconds.
'''),
  	16:  (pyIntFrame, 'HBWARNTIME', 'Heartbeat warntime.',
'''This frame is a heartbeat warning time measured in seconds.
'''),
  	17:  (pyCstringFrame, 'PATHNAME', 'file name',
'''This frame contains a pathname for a file as a C string.
'''),
  	18:  (pyNVpairFrame, 'NVPAIR', 'Name/value pair',
'''This frame contains a name/value pair - each of which is a NUL-terminated C-style string.
'''),
  	19:  (pyCstringFrame, 'JSDISCOVER', 'JSON-formatted discovery data',
'''This frame contains JSON-formatted output from a discovery process.  The type of discovery data and program collecting it are inside.
'''),
  	20:  (pyCstringFrame, 'PARAMNAME', 'Config parameter name',
'''This frame contains the name of a parameter to set in nanoprobe configuration - could be followed by a CSTRINGVAL or an IPADDR'''),
  	21:  (pyCstringFrame, 'CSTRINGVAL', 'String configuration value',
'This frame contains a string value to set in nanoprobe configuration.'),
  	22:  (pyIntFrame, 'CINTVAL', 'Integer configuration value',
'This frame contains an integer value to set into nanoprobe configuration.'),
  	23:  (pyIntFrame, 'ELAPSEDTIME', '64-bit elapsed time (usec)',
'''This frame provides elapsed time (measured locally) in microseconds.
In spite of the apparent variability permitted, it is an 8-byte (64-bit) integer.
'''),
  	24:  (pyCstringFrame, 'DISCNAME', 'name of this discovery action',
'''This frame is a name to give this instance of a discovery action.
'''),
  	25:  (pyIntFrame, 'DISCINTERVAL', 'Discovery interval',
'''This frame is a discovery repeat interval measured in seconds as an @ref IntFrame.
'''),
  	26:  (pyCstringFrame, 'DISCJSON', 'Discovery JSON string',
'''This frame provides the data describing the discovery action in detail.
   It must be preceded by a FRAMETYPE_DISCNAME.
'''),

    }
    _strframetypes = dict()
    for i in _intframetypes.keys():
        data = _intframetypes[i]
        key = data[1]
        _strframetypes[key] = (i, data[0], key, data[1], data[2])
    
    @staticmethod
    def get(key):
        if type(key) is str:
            return FrameTypes._strframetypes[key]
        else:
            if FrameTypes._intframetypes.has_key(int(key)):
                return FrameTypes._intframetypes[int(key)]
            return (None, str(key), str(key), str(key))

    @classmethod
    def c_defines(cls, f):
        l = FrameTypes._intframetypes.keys()
        l.sort()
        f.write(FrameTypes.fileheader % __file__)
        # Create pretty ASCII art pictures and #defines of all our different packet formats
        for i in l:
            tuple=FrameTypes._intframetypes[i]
            pyclass=tuple[0].__name__
            frametype=i
            framename=tuple[1]
            framedesc=tuple[1]
            frametext=tuple[3]
            Cclassname = re.sub('^py', '', pyclass)
            f.write('/**\n FRAMETYPE_%s Frame (<b>frametype %d</b>) Frame subclass - @ref %s\n' % (framename, frametype, Cclassname))
            f.write('<PRE>%s</PRE>\n%s\n */\n' % (FrameTypes.asciiart[pyclass] % i, frametext))
            f.write('#define FRAMETYPE_%s\t%d\t///< %s: @ref %s\n' % (tuple[1], i, tuple[2], Cclassname))
        f.write('///@}\n')
        f.write('///@}\n')
            
        # Create the frame type map - mapping frame types to function names in the 'C' code.
        f.write('#define	FRAMETYPEMAP	{\t\t\t\t\t\\\n')
        for i in l:
            tup = FrameTypes._intframetypes[i]
            clsname = tup[0].__name__
            Cclassname = re.sub('^py', '', clsname) + '_tlvconstructor'
            Cfuncname = Cclassname.lower()
            f.write('        {FRAMETYPE_%s,\t/*%d*/ %s},	\\\n' % (tup[1], i, Cfuncname))
        f.write('}\n')
# Create conventional class.DEFINENAME attributes
for s in FrameTypes._strframetypes.keys():
    setattr(FrameTypes, s, FrameTypes._strframetypes[s][0])

class FrameSetTypes:
    'Class defining the universe of FrameSets - including code to generate a C header file'
    None
    _fileheader = \
'''#ifndef _FRAMESETTYPES_H
#define _FRAMESETTYPES_H
/**
 * @file
 * @brief Header file defining all known FrameSet types
 * THIS FILE MECHANICALLY GENERATED by "%s".  DO NOT EDIT.
 *
 * @author &copy; 2011,2012 - Alan Robertson <alanr@unix.sh>
 * @n
 * Licensed under the GNU Lesser General Public License (LGPL) version 3 or any later version at your option.
 * excluding the provision allowing for relicensing under the GPL at your option.
 */
/**
 * @defgroup FrameSetTypes FrameSet Types
 *
 * @{
 * @ingroup DefineEnums
 */
'''
    _strframetypes = {
	# nanoprobe peer-peer packets
	'HEARTBEAT':	(1, 'A heartbeat packet'),
	'NAK':		(2, "We don't like the frameset mentioned"),
	'PING':		(3, 'Are you alive? (can also come from the CMA)'),
	'PONG':		(4,  'I am alive'),
	# nanoprobe packets sent to collective management authority
	'STARTUP':	(16, 'System originating packet looking for heartbeat configuration.'),
	'HBDEAD':	(17, 'System named in packet appears to be dead.'),
	'HBLATE':	(18, 'System named in packet appears to be dead.'),
	'HBBACKALIVE':	(19, 'System named in packet appears to be dead.'),
	'HBMARTIAN':	(20, 'System named in packet appears gave unexpected heartbeat.'),
	'PROBEALIVE':	(21, 'Packet issued by nanoprobe on startup - asking to be configured.'),
	'SWDISCOVER':	(22, 'Packet encapsulates switch discovery packet'),
	'JSDISCOVERY':	(23, 'Packet contains JSON-formatted discovery data'),
	# 'Privileged' packets sent from the CMA to nanoprobes
	'SENDHB':	(64, 'Send Heartbeats to these addresses'),
	'EXPECTHB':	(65, 'Expect (listen for) Heartbeats from these addresses'),
	'SENDEXPECTHB':	(66, 'Send Heartbeats to these addresses, and expect them as well.'),
	'STOPSENDHB':	(67, 'Stop sending Heartbeats to these addresses'),
	'STOPEXPECTHB':	(68, 'Stop expecting (listening for) Heartbeats from these addresses'),
	'STOPSENDEXPECTHB':(69, 'Stop sending Heartbeats to these addresses, and stop expecting them as well.'),
	'SETCONFIG':	(70, 'Initial configuration packet'),
	'INCRDEBUG':	(71, 'Increment debug for some or all classes'),
	'DECRDEBUG':	(72, 'Increment debug for some or all classes'),
	'DODISCOVER':	(73, 'Perform (repeating) JSON discovery action'),
	'STOPDISCOVER':	(74, 'Stop a repeating JSON discovery action'),
    }
    _intframetypes = dict()
    for s in _strframetypes.keys():
        i = _strframetypes[s][0]
        _intframetypes[i] = (s, _strframetypes[s][1])

    @staticmethod
    def get(key):
        if type(key) is str:
            return FrameSetTypes._strframetypes[key]
        else:
            if FrameSetTypes._intframetypes.has_key(int(key)):
                return FrameSetTypes._intframetypes[int(key)]
            return (None, str(int(key)), str(int(key)), str(int(key)))

    @classmethod
    def c_defines(cls, f):
        'Print out the C #defines that go with this set of definitions'
        f.write(FrameSetTypes._fileheader % __file__)
        l = FrameSetTypes._intframetypes.keys()
        l.sort()
        for i in l:
            tuple = FrameSetTypes._intframetypes[i]
            f.write('#define FRAMESETTYPE_%s\t%d\t///< %s\n' % (tuple[0], i, tuple[1]))
        f.write('///@}\n')
	# Don't currently want this map - probably not needed (or even a good idea...)
        #f.write('\n#define	FRAMESETTYPEMAP	{\t\t\t\t\t\t\\\n')
        for i in l:
            tup = FrameSetTypes._intframetypes[i]
            Cobjname = "frameset_listener_" + tup[0].lower()
            #f.write('        {FRAMESETTYPE_%s,\t/*%d*/ %s},	\\\n' % (tup[0], i, Cobjname))
        #f.write('}\n')
            
        f.write('#endif /* _FRAMESETTYPES_H */\n')

# Create conventional class.DEFINENAME attributes
for s in FrameSetTypes._strframetypes.keys():
    setattr(FrameSetTypes, s, FrameSetTypes._strframetypes[s][0])
     

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3 \
    or	( sys.argv[1] != "frametypes" and sys.argv[1] != "framesettypes"):
        sys.stderr.write("Usage: python %s (frametypes|framesettypes) output-filename\n" % sys.argv[0]);
        raise SystemExit(1)
    f = open(sys.argv[2], 'w')
    if sys.argv[1] == "frametypes":
        FrameTypes.c_defines(f)
        sys.exit(0)
    elif sys.argv[1] == "framesettypes":
        FrameSetTypes.c_defines(f)
        sys.exit(0)
    raise SystemExit(1)
