const textElement = document.getElementById("text")
const optionsButtonElement = document.getElementById("option-buttons")


let state = {}

function startGame() 
{
  state = {}
  showTextNode(1)
}

function showTextNode(textNodeIndex) 
{
  const textNode = textNodes.find(textNode => textNode.id === 
  textNodeIndex)
  textElement.innerText = textNode.text
}

function selectOption (option) 
{
  
}

const textNode = 
  [
    {
      id: 1,
      text: "You wake up in a strange place and you see a jar of blue goo near you.",
      options: 
      [
        {
          text: "Take the goo.",
          setState: {blueGoo: true},
          nextText: 2
        },
        {
            text:"Leave the goo.",
            nextText: 2
        }
      ]
    },
    {
      id: 2
    }
  ]

startGame()