#!/usr/bin/env node

const { readFileSync, writeFileSync } = require('fs');

function printUsage() {
  console.log(`hex2bin <source> <dest>`);
}

/**
 * 
 * @param {string} string 
 */
function parseByte(string) {
  const type = string[0];
  const digits = string.slice(1);

  if (digits.length !== 2) {
    console.log(digits)
  }

  switch (type) {
    case '%':
      return parseInt(digits, 2);
    case '$':
      return parseInt(digits, 16);
  }
}

(function () {
  if (process.argv.length < 4) {
    printUsage();
  }

  const source = process.argv[2];
  const dest = process.argv[3];

  console.log(`${source} to ${dest}`);

  const bytes = Uint8Array.from(
    readFileSync(source).toString()
      .split('\n')
      .map(line => line.trim())
      .filter(line => line[0] !== ';')
      .flatMap(line =>
        line.replace(/^\.db /g, '')
          .split(/,?\s+/)
      )
      .map(parseByte)
  );
  console.log(bytes);
  writeFileSync(dest, bytes);
})();