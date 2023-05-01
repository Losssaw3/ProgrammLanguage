#include "..//SunPosition/SunPosition.h"
using namespace SUN;


SunPosition::SunPosition(double Latitude, double Longitute)
	:Latitude(Latitude), Longitude(Longitute)
{
	Azimuth = into_range(Azimuth, 0, 360);
	Elevation = into_range(Elevation, -180, 180);
}

// Mean longitude of the sun Долгота солнца
double SunPosition::CalculateMeanLongitude()
{
	return dayNum * 0.01720279239 + 4.894967873;
}

//Mean anomaly of the Sun
double SunPosition::CalculateMeanAnomaly()
{
	return dayNum * 0.01720197034 + 6.240040768;
}

//Obliquity of the ecliptic 
double SunPosition::CalculateObliquity()
{
	return 0.4090877234 - 0.000000006981317008 * dayNum;
}


//Ecliptic longitude of the sun Эклиптическая долгота солнца
double SunPosition::CalculateEclipticLongitude()
{
	return (MeanLongitude + 0.03342305518 * sin(MeanAnomaly) + 0.0003490658504 * sin(2.0 * MeanAnomaly));
}

//Right ascension of the sun  
double SunPosition::CalculateRightAscension()
{
	return atan2(cos(Obliquity) * sin(EclipticLongitude), cos(EclipticLongitude));
}

//Declination of the sun
double SunPosition::CalculateDeclination()
{
	return asin(sin(Obliquity) * sin(EclipticLongitude));
}

//Local sidereal time  
double SunPosition::CalculateSiderealTime()
{
	return 4.894961213 + 6.300388099 * dayNum + RadLongitude;
}

//Hour angle of the sun  
double SunPosition::CalculateHourAngle()
{
	return Sidereal - RightAscension;
}

//Local elevation of the sun in degrees
double SunPosition::CalculateElevation()
{
	return degrees(asin(sin(Declination) * sin(RadLatitude) + cos(Declination) * cos(RadLatitude) * cos(HourAngle)));
}

//Local azimuth of the sun in degrees 
double SunPosition::CalculateAzimuth()
{
	return degrees(atan2(-cos(Declination) * cos(RadLatitude) * sin(HourAngle), sin(Declination) - sin(RadLatitude) * sin(radians(Elevation))));
}

std::ostream& SUN::operator<<(std::ostream& out, const SunPosition& point)
{
	out << "Высота: " << point.Elevation << " Азимут: " << point.Azimuth;
	return out;
}
