#!/usr/bin/node

// Import the request module
const request = require('request');

const filmId = process.argv[2]; // filmId is the third argument
const URL = 'https://swapi-api.hbtn.io/api/films/';

function action (_error, _response, body) {
  const episodeId = JSON.parse(body).episode_id;

  request(URL, function (_error, _response, body) {
    let i;
    const info = JSON.parse(body);

    for (i = 0; i < info.count; i++) {
      if (info.results[i].episode_id === episodeId) { break; }
    }

    const characters = info.results[i].characters;

    for (i = 0; i < characters.length; i++) {
      request(characters[i], function (_error, _response, body) {
        console.log(JSON.parse(body).name);
      });
    }
  });
}

// Make the request
request(URL + `${filmId}/`, action);
