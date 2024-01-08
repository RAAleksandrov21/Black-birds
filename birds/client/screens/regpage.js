import React from "react";
import {
  ImageBackground,
  SafeAreaView,
  StyleSheet,
  View,
  Text,
  Image,
  Platform,
  StatusBar,
  TouchableOpacity,
} from "react-native";

function Regpage({navigation}) {
  return (
    <View style={styles.container}>
      <TouchableOpacity
        style={styles.loginButton}
        onPress={() => navigation.navigate("Login")}
      >
        <Text>Log in</Text>
      </TouchableOpacity>
      <TouchableOpacity
        style={styles.registerButton}
        onPress={() => navigation.navigate("Register")}
      >
        <Text>Register</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    height: "30%",
    width: "100%",
    alignItems: "center",
    justifyContent: "center",
  },
  loginButton: {
    backgroundColor: "gold",
    padding: 10,
    alignItems: "center",
    borderRadius: 50,
  },
  registerButton: {
    backgroundColor: "gold",
    padding: 10,
    alignItems: "center",
    borderRadius: 50,
    margin: 10,
  },
});

export default Regpage;
