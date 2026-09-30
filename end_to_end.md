# End-to-End Verification

1. Load the Arduino program.
2. Test the HC-SR04 and LEDs in Proteus.
3. Import Database/Motion_db.sql into MySQL.
4. Put the PHP folder inside XAMPP htdocs.
5. Check database credentials in PHP/config.php.
6. Open the PHP dashboard in a browser.
7. POST distance and motion values to save_motion.php.
8. Confirm that events appear in the dashboard.

Note: Arduino Uno does not directly communicate with PHP/MySQL over a network. A serial-to-PC bridge or network-capable microcontroller is required for a physical real-time connection.
