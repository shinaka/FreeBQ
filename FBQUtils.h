
inline void LogError(PGM_P error) 
{ 
	char c;
	while ((c = pgm_read_byte(error++)) != 0)
		Serial.print(c);
	Serial.println();
}

inline void LogTrace(PGM_P msg)
{
	Serial.write("Trace: ");
	char c;
	while ((c = pgm_read_byte(msg++)) != 0)
		Serial.print(c);
	Serial.println();
}