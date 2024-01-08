import React, { useState } from "react";
import {
  Platform,
  StyleSheet,
  Text,
  TouchableOpacity,
  StatusBar,
  View,
  TextInput,
} from "react-native";

const Login = ({navigation}) => {
  return (
    <View style={styles.container}>
      <TextInput
        style={styles.input}
        placeholder="Password"
        textContentType="password"
        placeholderTextColor={"white"}
      />
      <TextInput
        style={styles.input}
        placeholder="Username"
        textContentType="username"
        placeholderTextColor={"white"}
      />
      <TouchableOpacity
        style={styles.submitButton}
        onPress={() => navigation.navigate("Home")}
      >
        <Text>Submit</Text>
      </TouchableOpacity>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    alignItems: "center",
    justifyContent: "center",
  },
  input: {
    height: 40,
    margin: 20,
    borderWidth: 1,
    padding: 10,
    width: "70%",
    borderColor: "white",
    borderRadius: 50,
    fontSize: 16,
  },
  submitButton: {
    backgroundColor: "gold",
    padding: 10,
    alignItems: "center",
    borderRadius: 50,
  },
});

export default Login;
