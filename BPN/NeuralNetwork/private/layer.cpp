#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>
#include <NeuralNetwork/public/layer.hpp>

#include <stdexcept>

namespace Layer = NeuralNetwork_ns::Layer;

Layer::ILayer::ILayer(NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction)
{
	SetLayerActivationFunction(ActivationFunction);
}

void Layer::ILayer::SetInputCount(NeuralNetwork_ns::numeric InputCount)
{
	m_nInputs = InputCount;
	InvalidateMatrix();
}

NeuralNetwork_ns::numeric Layer::ILayer::GetInputCount()
{
	return m_nInputs;
}

void Layer::ILayer::SetOutputCount(NeuralNetwork_ns::numeric OutputCount)
{
	m_nOutputs = OutputCount;
	InvalidateMatrix();
}

NeuralNetwork_ns::numeric Layer::ILayer::GetOutputCount()
{
	return m_nOutputs;
}

void Layer::ILayer::SetLayerWeights(NeuralNetwork_ns::layer_weights_t Weights)
{
	// Verify Size?
	m_Weights = Weights;
}

NeuralNetwork_ns::layer_weights_t Layer::ILayer::GetLayerWeights()
{
	return m_Weights;
}

void Layer::ILayer::SetLayerBiases(NeuralNetwork_ns::layer_biases_t Biases)
{
	// Verify Size?
	m_Bias = Biases;
}

NeuralNetwork_ns::layer_biases_t Layer::ILayer::GetLayerBiases()
{
	return m_Bias;
}

void Layer::ILayer::SetLayerActivationFunction(NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction)
{
	m_ActivationFunction = ActivationFunction;
}

NeuralNetwork_ns::ActivationFunction::IActivationFunction Layer::ILayer::GetLayerActivationFunction()
{
	return m_ActivationFunction;
}

void Layer::ILayer::InvalidateMatrix()
{
	m_Weights.resize(m_nInputs, m_nOutputs);
	m_Bias.resize(m_nOutputs, 1);
}

void Layer::ILayer::RandomizeMatrix()
{

}

NeuralNetwork_ns::layer_output_t Layer::ILayer::CalculateInducedLocalField(NeuralNetwork_ns::layer_input_t input)
{
	return m_Weights * input + m_Bias;
}

NeuralNetwork_ns::layer_output_t Layer::ILayer::CalculateOutput(NeuralNetwork_ns::layer_input_t input)
{
	return CalculateInducedLocalField(input).unaryExpr(m_ActivationFunction);
}