let paragraphCounter = 0;

function startGame() {
    for (let i = 0; i < 250; i++) {
        sendOutput("Welcome to Go Home!");
        
    }
    sendOutput("Welcome to Go Home!");
}

function getInput() {
    console.log("reached");
}

function updateOptions(options) {
    options.forEach(option => {
        
    });
}

/**
 * Displays the output parameter as text on the page.
 * @param {string} output The text to display on the page
 */
function sendOutput(output) {
    // Get the last paragraph's Id
    let lastParagraphId = "p".concat(paragraphCounter++).toString();
    let lastParagraph = document.getElementById(lastParagraphId);

    // Create a new paragraph as the last one's child
    let newParagraph = document.createElement("paragraph");
    newParagraph.setAttribute("class", "log");
    newParagraph.innerHTML = output;
    lastParagraph.appendChild(newParagraph);
}