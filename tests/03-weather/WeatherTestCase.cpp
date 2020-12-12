//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"


using ::testing::Return;
using ::testing::_;

TEST_F(WeatherTestCase, testWeatherGetResponseForCityApiErr) {
    cpr::Response responseApiErr;
    responseApiErr.status_code = 404;
    responseApiErr.text = "city not found";

    EXPECT_CALL(weatherMock, Get(_))
            .Times(1)
            .WillOnce(Return(responseApiErr));

    ASSERT_THROW(weatherMock.GetResponseForCity("N"), std::invalid_argument);
}

TEST_F(WeatherTestCase, testWeatherGetResponseForCity1) {
    EXPECT_CALL(weatherMock, Get(_))
            .Times(1)
            .WillOnce(Return(responseUfa));

    json jsonUfa = weatherMock.GetResponseForCity("Ufa");

    ASSERT_EQ(jsonUfa["status"], "ok");
}

TEST_F(WeatherTestCase, testWeatherGetResponseForCity2) {
    EXPECT_CALL(weatherMock, Get(_))
            .Times(1)
            .WillOnce(Return(responseMoscow));

    json jsonMoscow = weatherMock.GetResponseForCity("Moscow");

    ASSERT_EQ(jsonMoscow["status"], "ok");
}

TEST_F(WeatherTestCase, testGetTemperature1) {
    EXPECT_CALL(weatherMock, Get(_))
            .Times(1)
            .WillOnce(Return(responseUfa));

    ASSERT_FLOAT_EQ(weatherMock.GetTemperature("Ufa"), -22);
}

TEST_F(WeatherTestCase, testGetTemperature2) {
    EXPECT_CALL(weatherMock, Get(_))
            .Times(1)
            .WillOnce(Return(responseMoscow));

    ASSERT_FLOAT_EQ(weatherMock.GetTemperature("Moscow"), -10.08);
}

TEST_F(WeatherTestCase, testGetDifferenceString1) {
    EXPECT_CALL(weatherMock, Get(_))
            .Times(2)
            .WillOnce(Return(responseUfa))
            .WillOnce(Return(responseMoscow));

    ASSERT_TRUE(weatherMock.GetDifferenceString("Ufa", "Moscow") ==
                "Weather in Ufa is colder than in Moscow by 11 degrees");
}

TEST_F(WeatherTestCase, testGetDifferenceString2) {
    EXPECT_CALL(weatherMock, Get(_))
            .Times(2)
            .WillOnce(Return(responseMoscow))
            .WillOnce(Return(responseUfa));

    ASSERT_TRUE(weatherMock.GetDifferenceString("Moscow", "Ufa") ==
                "Weather in Moscow is warmer than in Ufa by 11 degrees");
}

TEST_F(WeatherTestCase, testFindDiffBetweenTwoCities1) {
    EXPECT_CALL(weatherMock, Get(_)).Times(2)
            .WillOnce(Return(responseUfa))
            .WillOnce(Return(responseMoscow));

    ASSERT_FLOAT_EQ(weatherMock.FindDiffBetweenTwoCities("Ufa", "Moscow"), -11.92);
}

TEST_F(WeatherTestCase, testSetApiKey1) {
    ASSERT_NO_THROW(weatherMock.SetApiKey("faf5c6716a6f9b9e6798927144f2aa19"));
}
