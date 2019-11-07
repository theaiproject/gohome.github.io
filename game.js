const textElement = document.getElementById('text')
const optionButtonsElement = document.getElementById('option-buttons')

let state = {}

function startGame() {
  state = {}
  showTextNode(1)
}

function showTextNode(textNodeIndex) {
  const textNode = textNodes.find(textNode => textNode.id === 
  textNodeIndex)
  textElement.innerText = textNode.text
  while(optionButtonsElement.firstChild) {
    optionButtonsElement.removeChild(optionButtonsElement.firstChild)
  }
  
  textNode.options.forEach(option => {
    if (showOption(option)) {
      const button = document.createElement('button')
      button.innerText = option.text
      button.classList.add('btn')
      button.addEventListener('click', () => selectOption(option))
      optionButtonsElement.appendChild(button)
    }
  })
}

function showOption(option) {
  return option.requiredState == null || option.requiredState(state)
}

function selectOption(option) {
  const nextTextNodeId = option.nextText
  if (nextTextNodeId <= 0) {
    return startGame()
  }
  state = Object.assign(state, option.setState)
  showTextNode(nextTextNodeId)
}

const textNodes = [
  {
    id: 1,
    text: 'The last few weeks have been normal enough. There have been news articles about a mysterious illness lately, but nothing out of the ordinary. Its all just a distraction anyways. You know better than to fall for all the garbage. Speaking of the man, this job sucks and you know it. Youve been falling asleep after lunch every day this week and nobody has said a word yet... Today is Thursday. You know youll probably be fired soon, but who cares? Your story begins here. Time to wake up...',
    options: 
    [
      {
        text: 'Wake up.',
        nextText: 2
        //done
      },
      {
      text: 'Sleep a little longer.',
      nextText: 3
      //done
      }
    ]
  },
  {
    id: 2,
    text: 'You wake up to the sound of clattering somewhere nearby. Shaking off the stiffness that comes with sleeping with your head on the hard wooden desk in your cubicle, you notice that the office is pitch dark, your cubicle an island of illumination due to your small desk lamp. Standing up and stretching, you decide to...',
    options: [
      {
        text: 'Gather your things and head towards the parking garage.',
        /*requiredState:  (currentState) => currentState.blueGoo,*/
       /* setState: { blueGoo: false, sword: true},*/
        nextText: 4
        //done
      },
      {
        text: 'Have a look around.',
        nextText: 5
        //done
      }
    ]
  },
  {
    id: 3,
    text: 'You are eaten by a terrible monster as you day dream of far away lands.',
    options: 
    [
      {
        text: 'Restart',
        nextText: -1
      },
    ]
  },
  {
    id: 4,
    text: 'You get halfway down the hall and realize you forgot your favorite thermos.',
    options: 
    [
      {
         text: 'Go back and get it',
         nextText: 6
         //done
      },
      {
        text: 'Fuck it. Ill pack it up in my box of shit when they fire me.',
        nextText: 7
        //done
      }
    ]
  },
  {
    id: 5,
    text: 'You flick off the lamp light and peer into the darkness of the office, searching for signs of life. After letting your eyes adjust, you notice a figure slowly approaching your cubicle with an odd gait.',
    options: 
    [
      {
        text: 'Approach the figure.',
        nextText: 8
        //done
      },
      {
        text: 'Call out to them.',
        nextText: 9
        //done
      }
    ]
  },
  {
    id: 6,
    text: 'Ben the janitor is snooping round your desk',
    options: [
      {
        text: 'I really want the thermos.',
        nextText: 10
        //done
      },
      {
        text: 'Dodge Ben, the renderer',
        nextText: 11
        //done
      }
    ]
  },
  {
    id: 7,
    text: 'You go to the elevator and ride it down to the parking garage and escape. You Win!',
    options: 
    [
      {
        text:'Congrats! Play Again?',
        nextText: -1
      }
    ]
  },
  {
    id: 8,
    text:'You walk out of your cubicle and ask the figure what theyre doing here so late with the lights off; however, a few feet from the individual, you stop dead in your tracks. Ben, the custodian, flinches at the sound of your voice and turns to face you, revealing a grotesque mask of flesh. The left side of his face has been all but removed.',
    options: 
    [
      {
        text:'Fucking. Bail.',
        nextText: 12
        //done
      },
      {
        text:'Holy shit Ben - your face! Weve got to get you to a hospital!',
        nextText: 13
        //done
      }
    ]
  },
  {
    id: 13,
    text: 'While you are still in shock at the site standing before you, Bens deformed face stretches wide as he opens his mouth like a snake before embracing you and tearing open your jugular.',
    options: 
    [
      {
        text: 'Restart',
        nextText: -1
      }
    ]
    
  },
  {
    id: 11,
    text: 'Nod at Ben and bail with your thermos. Ben grabs your arm in a flash and takes a massive bite after bite. You scream in horror as you pull back a bloody stump and fall to the floor. You never heard bens undead moans over your own screaming as he fell upon you.',
    options: 
    [
      {
        text: 'Restart',
        nextText: -1
      }
    ]
  },
  {
    id: 9,
    text: 'You call out to ben, asking him what he is doing here so late. As he steps closer to the sound of your voice, you realize that this is a zombie.',
    options: 
    [
      {
        text: 'Fucking. Bail.',
        nextText: 12
        //done
      },
      {
        text: 'Holy shit Ben - your face! Weve got to get you to a hospital!',
        nextText: 13
        //done
      }
    ]
  },
  {
    id: 10,
    text: 'Ben is oddly just hovering over your desk',
    options:
    [
      {
        text: 'Hey man, can I help you with something?',
        nextText: 14
        //done
      },
      {
        text: 'Nod at Ben and bail with your thermos',
        nextText:15
        //done
      }
    ]
  },
  {
    id: 12,
    text: 'You bail. turning around, you sprint to the lobby faster than you ever thought you could. you hear squelching of wet flesh dropping to the floor behind you as Ben - or... whats left of him - shambles down the hall after you. You run past the receptionists desk on your left and mash the elevator button furiously. In a panic, you remember there being a stairwell if you keep going past the receptionists desk.',
    options:
    [
      {
      text: 'Wait for the elevator',
      nextText: 17
      //done
      },
      {
        text: 'Try to find the stairs',
        nextText: 18
        //done
      }
    ]
  },
  {
    id: 14,
    text:'Ben flinches at the sound of your voice and turns to face you, revealing a grotesque mask of flesh. The left side of his face has been all but removed.',
    options: 
    [
      {
        text:'Fucking. Bail.',
        nextText: 15
        //done
      },
      {
        text:'Holy shit Ben - your face! Weve got to get you to a hospital!',
        nextText: 13
        //done
      }
    ]
  },
  {
    id: 17,
    text: 'You hear the familiar ding of the elevators arrival as you see ben turn the corner of the lobby. The look in his remaining eye betray a supernatural hunger that turns your blood to ice. You jump in the elevator and hit the door close button hard enough that it cracks in your hand. Youve never seen elevator doors take so long to close. You stand back as ben approaches...gaping his vicious maw and barking with a madmans ferocity. Just as the doors are about to close, the automatic sensors detect Ben and reopen again. You can almost see the grin where bens face used to be as he sinks his mangled teeth into your throat.',
    options: 
    [
      {
        text:'Restart',
        nextText: -1
      },
    ]
  },
  {
    id: 18,
    text:'The elevator is taking way too fucking long. You make a dash for the stairs on the other side of the office just as Ben turns the corner of the lobby. The look in his remaining eye betrays a supernatural hunger that turns your blood to ice. Pushing through the crippling panic, you dash through the cubicles on this side of the office - what you find brings a tear to your eye. Turning the last corner before you reach the stairwell is another walking corpse - Brenda, the receptionist in her business jacket and skirt ensemble - now red',
    options:
    [
      {
        text:'Push past Brenda',
        nextText: 19
        //done
      },
      {
        text:'Jump over a nearby cubicle wall.',
        nextText: 20
        //done
      }
    ]
  },
  {
    id: 15,
    text:'You bail. turning around, you sprint to the lobby faster than you ever thought you could. you hear squelching of wet flesh dropping to the floor behind you as Ben - or... whats left of him - shambles down the hall after you. You run past the receptionists desk on your left and mash the elevator button furiously. In a panic, you remember there being a stairwell if you keep going past the receptionists desk.',
    options:
    [
      {
        text:'Wait for the elevator',
        nextText: 17
        //done
      },
      {
        text:'Try to find the stairs',
        nextText: 21
        //done
      }
    ]
  },
  {
    id: 19,
    text:'Channeling all the time you spend watching mma, you outmaneuver and charge past Ben to the stairwell entrance. You close the stairwell door on Ben and Brenda and lock it just as they shove their gruesome faces up against the steel mesh reinforced window. you remember the floor above you is roof access, and youre on the 5th floor. The parking garage is B1',
    options:
    [
      {
        text:'Go to the roof',
        nextText: 22
        //done
      },
      {
        text:'Go to the parking garage',
        nextText: 23
        //done
      }
    ]
  },
  {
    id: 20,
    text:'The cubicle wall collapses under your weight and you fall face first on to a desk. nose bleeding and head ringing, you stumble out of the cubicle into Brenda arms, who greets you by ripping out your throat',
    options:
    [
      {
        text:'Restart',
        nextText:-1
      },
    ]
  },
  {
    id: 21,
    text:'Channeling all the time you spend watching mma, you outmaneuver and charge past Brenda to the stairwell entrance. You close the stairwell door on Ben and Brenda and lock it just as they shove their gruesome faces up against the steel mesh reinforced window. you remember the floor above you is roof access, and youre on the 5th floor. The parking garage is B1',
    options:
    [
      {
        text:'Go to the roof.',
        nextText:22
        //done
      },
      {
        text:'Go to the parking garage.',
        nextText: 23
        //done
      }
    ]
  },
  {
    id: 22,
    text:'A short climb later, you open the roof access door and greet the cool night air. The moment cant be savored for long. You see fires in the distance, parked police lights and with no police nearby, paper and trash strewn about the streets below, and hear the occasional blood-curdling scream as someone else falls victim to this nightmare',
    options:
    [
      {
        text:'Sit and wait... maybe jump.',
        nextText: 24
        //done
      },
      {
        text:'Keep moving. Ive got to get to my car.',
        nextText: 23
        //done
      }
    ]
  },
  {
    id: 23,
    text:'You head down the stairs to the parking garage and escape. You win!',
    options:
    [
      {
        text:'Play again?',
        nextText: -1
      }
    ]
  },
  {
    id: 24,
    text:'You approach the edge of the roof and take a seat on the edge. You start to think of how all the problems you were dealing with are now going to completely change. Your life is going to be different now.  Dark thoughts of a solution for all of those problems creep into your mind.',
    options:
    [
      {
        text: 'Wait a little longer... maybe jump.',
        nextText: 25
        //done
      },
      {
        text:'Stand up.',
        nextText: 26
      }
    ]
  },
  {
    id: 25,
    text:'Another blood-curdling scream arises from somewhere in the distance. That was just enough to clear your mind and get you back to the present. You stand up, turn around and head for the door.',
    options:
    [
      {
        text:'Go to parking garage',
        nextText: 23
      } 
    ]
  },
  {
    id: 26,
    text:'You stand up and step off. You relish the cool breeze for the final time.',
    options:
    [
      {
        text:'=\'( Play Again?',
        nextText: -1
      }
    ]
  }
]

startGame()

