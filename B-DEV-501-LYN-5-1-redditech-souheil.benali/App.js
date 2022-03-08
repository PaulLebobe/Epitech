/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React, { useState } from 'react';
import {
  Button,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
  Image,
} from 'react-native';

import { NavigationContainer } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';

import { authorize } from 'react-native-app-auth';
import Home from './pages/Home.js'
import accueil from './pages/accueil.png'
import Mysearchbar from './pages/Searchbar';
import searchlogo from './pages/search.png'
import profillogo from './pages/profil.png'
import ProfileConnected from './pages/Profile'
import Setting from './pages/Setting.js';
import settinglogo from './pages/settings.png';
import librarylogo from './pages/library.png'
import Subreddit from './pages/Subredit.js';
import { ProvideAuth, useAuth } from './src/utils/useAuth.js';




const Tab = createBottomTabNavigator();

function MyTabBar() {
  const auth = useAuth();
  function Profile() {
    return (
      <View style={styles.app}>
        <View style={styles.connect_button}>
          <Button
            title="Connect With REDDIT"
            onPress={() => { auth.Authenticate() }}
          />
        </View>
        <Image
          source={require('./logo.png')}
          style={styles.logo} />
        <Text style={styles.titleText}>MY_REDDITECH</Text>
      </View>);
  }
  return ((auth.token == null ?
    <Tab.Navigator
      initialRouteName="Profil"
      screenOptions={{
        tabBarActiveTintColor: '#FF5700',
      }}
    >
      <Tab.Screen
        name="Home"
        component={Home}
        options={{
          tabBarLabel: 'Home',
          tabBarIcon: () => (
            <Image
              source={accueil}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
      <Tab.Screen
        name="Search"
        component={Mysearchbar}
        options={{
          tabBarLabel: 'Search',
          tabBarIcon: () => (
            <Image
              source={searchlogo}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
      <Tab.Screen
        name="Profile"
        component={Profile}
        options={{
          tabBarLabel: 'Profile',
          tabBarIcon: () => (
            <Image
              source={profillogo}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
    </Tab.Navigator> : <Tab.Navigator
      initialRouteName="Home"
      screenOptions={{
        tabBarActiveTintColor: '#FF5700',
      }}
    >
      <Tab.Screen
        name="Home"
        component={Home}
        options={{
          tabBarLabel: 'Home',
          tabBarIcon: () => (
            <Image
              source={accueil}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
      <Tab.Screen
        name="Search"
        component={Mysearchbar}
        options={{
          tabBarLabel: 'Search',
          tabBarIcon: () => (
            <Image
              source={searchlogo}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
      <Tab.Screen
        name="Profile"
        component={ProfileConnected}
        options={{
          tabBarLabel: 'Profile',
          tabBarIcon: () => (
            <Image
              source={profillogo}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
      <Tab.Screen
        name="Sub"
        component={Subreddit}
        options={{
          tabBarLabel: 'Sub',
          tabBarIcon: () => (
            <Image
              source={librarylogo}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
      <Tab.Screen
        name="Setting"
        component={Setting}
        options={{
          tabBarLabel: 'Setting',
          tabBarIcon: () => (
            <Image
              source={settinglogo}
              style={{ height: 30, width: 30 }}
            />
          ),
        }}
      />
    </Tab.Navigator>))
}

const config = {
  redirectUrl: 'com.myapp://oauth2redirect/reddit',
  clientId: '9xzEJ3GMorwyUnu-HgdCFg',
  clientSecret: '',
  scopes: ['identity'],
  serviceConfiguration: {
    authorizationEndpoint: 'https://www.reddit.com/api/v1/authorize.compact',
    tokenEndpoint: 'https://www.reddit.com/api/v1/access_token',
  },
  customHeaders: {
    token: {
      Authorization: 'Basic OXh6RUozR01vcnd5VW51LUhnZENGZw==',
    },
  },
};


const App = () => {

  return (
    <ProvideAuth>
      <NavigationContainer><MyTabBar /></NavigationContainer>
    </ProvideAuth>
  );
}

const styles = StyleSheet.create({
  app: {
    backgroundColor: '#FF5700',
    flex: 1,
  },
  logo: {
    width: 80,
    height: 80,
    left: 30,
    top: 250,
    resizeMode: 'contain',
  },
  titleText: {
    fontSize: 35,
    left: 100,
    top: 200,
    fontWeight: "bold",
    color: 'rgb(255, 255, 255)',
  },
  connect_button: {
    width: '45.8%',
    position: 'absolute',
    bottom: 300,
    right: 120,
    alignSelf: 'flex-end',
  }
});

export default App;
