#making a simple reflex agent for the condition where you pull your hand away if the object is hot

class Environment:
    def __init__(self, heat_level = "high"):
        self.heat_level = heat_level
    
    '''getter to get the percept'''    
    def get_percept(self):
        if self.heat_level == "high":
            return "Hot"
        else:
            return "Cold"

#simple reflex agent
class Simple_Reflex_Agent:
    def action(self, percept):
        if percept == "Hot":
            return "PULL YOUR HAND AWAY!"
        else:
            return "NO ACTION NEEDED!"
        

#performing the action

#first we will make the objects of the respective classes
environment = Environment(heat_level="high")
agent = Simple_Reflex_Agent()

#then we willl extract the percept that is needed by the agent 
percept = environment.get_percept()

#once the percept is found then the action is decided,
#like what should the agent do ; how should it act!
actions = agent.action(percept)

print(f"Percept: {percept}, Action: {actions}")
