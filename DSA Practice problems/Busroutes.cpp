class Solution {
public:
    int  numBusesToDestination(vector<vector<int>>& routes, int source, int target) { 
       
        if  (source == target) {
            return 0;
        }

         unordered_map<int,  vector<int>> stopToRoutes;
          for (int routeId = 0;  routeId  < routes.size(); routeId++) { 
             for (int stop : routes[routeId]) { 
                stopToRoutes[stop].push_back(routeId);
            }
        }
        queue<int>  routeQueue;
        vector<bool>  visitedRoute(routes.size(), false);
        for (int route :  stopToRoutes[source]) {
            routeQueue.push(route);
            visitedRoute[route] = true;
        }

        int  busCount = 1;  

        while  (!routeQueue.empty()) { 
            int  currentLevelSize  = routeQueue.size(); 
            
          for  (int i = 0; i < currentLevelSize; i++) { 
                int currentRoute = routeQueue.front();
                routeQueue.pop();

                 for (int stop : routes[currentRoute]) {
                    
                    if  (stop == target) {
                         return busCount;
                    }

                    
                      for (int connectingRoute : stopToRoutes[stop]) {
                        if (!visitedRoute[connectingRoute]) {
                            visitedRoute[connectingRoute] = true;
                            routeQueue.push(connectingRoute);
                        }
                    }
                }
            }
              busCount++;
        }

          return -1;
    }
}; 