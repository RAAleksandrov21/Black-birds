import React, { useState } from "react";
import {
  Platform,
  StyleSheet,
  Text,
  View,
  StatusBar,
  SafeAreaView,
  TextInput,
} from "react-native";

const Login = () => {
  return (
    <SafeAreaView style={styles.container}>
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
    </SafeAreaView>
  );
};

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
  input: {
    height: 40,
    margin: 20,
    borderWidth: 1,
    padding: 10,
    width: "50%",
    borderColor: "white",
  },
});

export default Login;
