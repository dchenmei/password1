# Password1 

Every year, I have to come up with new passwords for numerous accounts. Since passwords are *string* of something, I wrote **password1** to generate secure passwords without hassle.

## Methods 

**password1** includes four common password generation methods. 

**Random**: also known as psychopath method, randomly generates a password of a given length.

**Schneier**: from cybersecurity expert Bruce Schneier, generates a password from pieces of a sentence.

**Electrum**: bitcoin wallet method, uses twelve words as seeds to create a sequence. 

**PAO**: mnemonic method, creates a memorable sentence various adjectives, nouns and verbs.

## Compile

After download and unzip:

```sh
cd password1
make 
```
## Usage

On command line tool of choice:

```sh
./password1 o l
```

**o**: option for methods - random (1), schneier (2), electrum (3), PAO (4)    
**l**: password length, only required for random method 



