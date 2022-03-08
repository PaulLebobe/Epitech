import { authorize } from 'react-native-app-auth';
import axios from "axios"

const config = {
    redirectUrl: 'com.myapp://oauth2redirect/reddit',
    clientId: '9xzEJ3GMorwyUnu-HgdCFg',
    clientSecret: '',
    scopes: ['identity', 'edit', 'subscribe', 'save', 'submit', 'read', 'modconfig', 'account', 'vote', 'flair', 'mysubreddits'],
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


async function GenToken() {
    try {
        const authState = await authorize(config);
        return (await Promise.resolve({token: authState.accessToken, validity: authState.accessTokenExpirationDate, refreshToken: authState.refreshToken}))
    } catch (e) {
    }

}

async function GetSubreddit(token) {
    const options = {
        method: 'GET',
        url: 'https://oauth.reddit.com/subreddits/mine',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            Authorization: "Bearer " + token,
        },
    };
    return await axios.request(options)
};

async function GetProfile(token) {
    const options = {
        method: 'GET',
        url: 'https://oauth.reddit.com/api/v1/me',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            Authorization: "Bearer " + token,
        },
    };
    return await axios.request(options)
}

async function GetPrefs(token) {
    const options = {
        method: 'GET',
        url: 'https://oauth.reddit.com/api/v1/me/prefs',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            Authorization: "Bearer " + token,
        },
    };
    return await axios.request(options)
}

module.exports = {
    GetSubreddit,
    GenToken,
    GetProfile,
    GetPrefs,
}