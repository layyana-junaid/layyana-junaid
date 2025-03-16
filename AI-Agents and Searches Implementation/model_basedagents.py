#understanding what is a model based agent and how it works 
#model based agents basically work on past experiences 
#we'll look at the closing the window when it rains example to understand it 

class Environment:
    def __init__(self, rain = "No", windows_open = "Open"):
        self.rain = rain 
        self.windows_open = windows_open
    
    #getter to return the initial conditions(percept)    
    def get_percept(self):
        return {"rain" : self.rain, "windows_open" : self.windows_open}
    
    #defining the condition for closing the windows 
    def closing_windows(self):
        if self.windows_open == "Open":
            self.windows_open = "Close"
    '''i.e if they were opened initially then close them when 
    closing a window is required'''
    
    
class Model_Based_Agent:
    def __init__(self):
        self.model = {'rain' : 'No', 'windows_open' : 'Open'}
        
    def act(self, percept):
        self.model.update(percept)