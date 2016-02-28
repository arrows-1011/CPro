function displayInformation() {
     // var library is defined, use it to print the information
    for (var i = 0 ; i < 3 ; i++) {
        if (library[i].readingStatus == true) {
            console.log("Already read '" + library[i].title + "' by " + library[i].author + ".");
        } else {
            console.log("You still need to read '" + library[i].title + "' by " + library[i].author + ".");   
        }
    }
} 

// tail starts here
var library = [ 
    {
        title: 'Bill Gates',
        author: 'The Road Ahead',
        readingStatus: true
    },
    {
        title: 'Steve Jobs',
        author: 'Walter Isaacson',
        readingStatus: true
    },
    {
        title: 'Mockingjay: The Final Book of The Hunger Games',
        author: 'Suzanne Collins',
        readingStatus: false
    }
];

displayInformation();
