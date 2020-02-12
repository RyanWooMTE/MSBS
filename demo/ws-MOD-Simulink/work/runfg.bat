C:
cd C:\Program Files\FlightGear

SET FG_ROOT=C:\Program Files\FlightGear\\data
.\\bin\\win32\\fgfs --aircraft=paraglider --fdm=network,localhost,5501,5502,5503 --fog-fastest --disable-clouds --start-date-lat=2004:06:01:09:00:00 --disable-sound --in-air --enable-freeze --airport=KXMR --runway=13 --altitude=3297 --heading=100 --offset-distance=3.5 --offset-azimuth=0
