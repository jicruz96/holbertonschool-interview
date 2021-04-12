#!/usr/bin/node

// Import the request module
const request = require('request');
const URL = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/';

async function getCharacterName (url) {
  return new Promise((resolve, reject) => {
    request(url, (_err, _res, body) => { resolve(JSON.parse(body).name); });
  });
}

async function printCharacters (_error, _response, body) {
  for (const url of JSON.parse(body).characters) {
    const characterName = await getCharacterName(url);

    console.log(characterName);
  }
}

request(URL, printCharacters);
