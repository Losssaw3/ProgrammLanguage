#pragma once
#include "Math.h"
#include "Date.h"

namespace SUN
{
	class SunPosition
	{
	public:
		friend std::ostream& operator<< (std::ostream& out, const SunPosition& point);
		SunPosition(double Latitude , double Longitude);

	private:
		double Latitude;

		double Longitude;

		double dayNum = FromUnixToJ2000();
		// Mean longitude of the sun Долгота солнца
		double CalculateMeanLongitude();

		//Mean anomaly of the Sun
		double CalculateMeanAnomaly();

		//Obliquity of the ecliptic 
		double CalculateObliquity();

		//Ecliptic longitude of the sun Эклиптическая долгота солнца
		double CalculateEclipticLongitude();

		//Right ascension of the sun  
		double CalculateRightAscension();

		//Declination of the sun
		double CalculateDeclination();

		//Local sidereal time  
		double CalculateSiderealTime();

		//Hour angle of the sun  
		double CalculateHourAngle();

		//Local elevation of the sun in degrees
		double CalculateElevation();

		//Local azimuth of the sun in degrees 
		double CalculateAzimuth();

		double RadLatitude = radians(Latitude);

		double RadLongitude = radians(Longitude);		

		double MeanLongitude = CalculateMeanLongitude();

		double MeanAnomaly = CalculateMeanAnomaly();

		double Obliquity = CalculateObliquity();

		double EclipticLongitude = CalculateEclipticLongitude();

		double RightAscension = CalculateRightAscension();

		double Declination = CalculateDeclination();

		double Sidereal = CalculateSiderealTime();

		double HourAngle = CalculateHourAngle();

		double Elevation = CalculateElevation();

		double Azimuth = CalculateAzimuth();
	};
}



