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
  Button,
} from "react-native";

function Regpage({navigation}) {
  return (
    <View style={styles.container}>
      <Button
        title="Log in"
        onPress={() => navigation.navigate("Login")}
        style={styles.registerButton}
      />
      <Button
        title="Register"
        onPress={() => navigation.navigate("Register")}
        style={styles.loginButton}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "dodgerblue",
    height: "30%",
    width: "100%",
    alignItems: "center",
    justifyContent: "center",
  },

});

export default Regpage;
