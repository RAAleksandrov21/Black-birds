import * as React from "react";
import {
  Platform,
  StyleSheet,
  Text,
  View,
  StatusBar,
  SafeAreaView,
} from "react-native";
import WelcomeScreen from "./screens/welcome";
import { NavigationContainer } from "@react-navigation/native";
import {createNativeStackNavigator} from "react-native-screens/native-stack"
import Regpage from "./screens/regpage";
const App = () => {
  const Stack = createNativeStackNavigator();
  return (
    <NavigationContainer>
      <Stack.Navigator>
        <Stack.Screen name="Home" component={WelcomeScreen} />
        <Stack.Screen name="Regpage" component={Regpage} />
      </Stack.Navigator>
    </NavigationContainer>
  );
};





export default App;
